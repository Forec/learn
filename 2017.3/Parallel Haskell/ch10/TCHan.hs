import Control.Concurrent.STM (
  STM,
  TVar,
  orElse,
  newTVar,
  readTVar,
  writeTVar,
  retry,
  atomically)

data TChan a = TChan (TVar (TVarList a))
                     (TVar (TVarList a))
type TVarList a = TVar (TList a)
data TList a = TNil | TCons a (TVarList a)

newTChan :: STM (TChan a)
newTChan = do
  hole <- newTVar TNil
  read <- newTVar hole
  write <- newTVar hole
  return (TChan read write)

readTChan :: TChan a -> STM a
readTChan (TChan readVar _) = do
  listHead <- readTVar readVar
  head <- readTVar listHead
  case head of
    TNil -> retry
    TCons val tail -> do
      writeTVar readVar tail
      return val

writeTChan :: TChan a -> a -> STM ()
writeTChan (TChan _ writeVar) a = do
  newListEnd <- newTVar TNil
  listEnd <- readTVar writeVar
  writeTVar writeVar newListEnd
  writeTVar listEnd (TCons a newListEnd)

dupTChan :: TChan a -> STM (TChan a)
dupTChan (TChan _ writeVar) = do
  hole <- readTVar writeVar
  newReadVar <- newTVar hole
  return (TChan newReadVar writeVar)

unGetTChan :: TChan a -> a -> STM ()
unGetTChan (TChan readVar _) a = do
  listHead <- readTVar readVar
  newHead <- newTVar (TCons a listHead)
  writeTVar readVar newHead

isEmptyTChan :: TChan a -> STM Bool
isEmptyTChan (TChan read _write) = do
  listhead <- readTVar read
  head <- readTVar listhead
  case head of
    TNil -> return True
    TCons _ _ -> return False

readEitherTChan :: TChan a -> TChan b -> STM (Either a b)
readEitherTChan a b = 
  fmap Left (readTChan a)
    `orElse`
  fmap Right (readTChan b)

main :: IO ()
main = do
  c <- atomically newTChan
  atomically $ writeTChan c 'a'
  atomically (readTChan c) >>= print
  atomically (isEmptyTChan c) >>= print
  atomically $ unGetTChan c 'a'
  atomically (isEmptyTChan c) >>= print
  atomically (readTChan c) >>= print
  c2 <- atomically $ dupTChan c
  atomically $ writeTChan c 'b'
  atomically (readTChan c) >>= print
  atomically (readTChan c2) >>= print
