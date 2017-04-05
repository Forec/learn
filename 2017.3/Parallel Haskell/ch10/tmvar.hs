module TMVar where

import Control.Concurrent.STM hiding (TMVar, takeTMVar)

newtype TMVar a = TMVar (TVar (Maybe a))

newTMVar :: a -> STM (TMVar a)
newTMVar a = do
  t <- newTVar (Just a)
  return (TMVar t)

newEmptyTMVar :: STM (TMVar a)
newEmptyTMVar = do
  t <- newTVar Nothing
  return (TMVar t)

takeTMVar :: TMVar a -> STM a
takeTMVar (TMVar t) = do
  m <- readTVar t
  case m of
    Nothing -> retry
    Just a  -> do
      writeTVar t Nothing
      return a

putTMVar :: TMVar a -> a -> STM ()
putTMVar (TMVar t) a = do
  m <- readTVar t
  case m of
    Nothing -> do
      writeTVar t (Just a)
      return ()
    Just _ -> retry

takeEitherTMVar :: TMVar a -> TMVar b -> STM (Either a b)
takeEitherTMVar ma mb = 
  fmap Left (takeTMVar ma)
    `orElse`
  fmap Right (takeTMVar mb)
