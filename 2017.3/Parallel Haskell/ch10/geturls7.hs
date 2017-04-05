{-# LANGUAGE CPP #-}

import GetURL

import Control.Concurrent
import Control.Exception
import qualified Data.ByteString as B
import Control.Concurrent.STM

data Async a = Async ThreadId (TMVar (Either SomeException a))

async :: IO a -> IO (Async a)
async action = do
  var <- newEmptyTMVarIO
  t <- forkFinally action (atomically . putTMVar var)
  return (Async t var)

waitCatch :: Async a -> IO (Either SomeException a)
waitCatch = atomically . waitCatchSTM

waitCatchSTM :: Async a -> STM (Either SomeException a)
waitCatchSTM (Async _ var) = readTMVar var

waitSTM :: Async a -> STM a
waitSTM a = do
  r <- waitCatchSTM a
  case r of
    Left e  -> throwSTM e
    Right a -> return a

wait :: Async a -> IO a
wait = atomically . waitSTM

cancel :: Async a -> IO ()
cancel (Async t _) = throwTo t ThreadKilled

waitEither :: Async a -> Async b -> IO (Either a b)
waitEither a b = atomically $
  fmap Left (waitSTM a)
   `orElse`
  fmap Right (waitSTM b)

waitAny :: [Async a] -> IO a
waitAny asyncs = 
  atomically $ foldr (orElse . waitSTM) retry asyncs

withAsync :: IO a -> (Async a -> IO b) -> IO b
withAsync io = bracket (async io) cancel

main =
  withAsync (getURL "https://www.baidu.com") $ \a1 ->
  withAsync (getURL "http://forec.cn") $ \a2 -> do
  r1 <- wait a1
  r2 <- wait a2
  print (B.length r1, B.length r2)