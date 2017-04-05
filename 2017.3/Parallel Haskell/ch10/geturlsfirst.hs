{-# LANGUAGE CPP #-}
module Main where

import GetURL
import Control.Concurrent
import Control.Exception
import Control.Concurrent.STM
import Text.Printf
import qualified Data.ByteString as B

data Async a = Async ThreadId (TMVar (Either SomeException a))

async :: IO a -> IO (Async a)
async action = do
  var <- newEmptyTMVarIO
  t <- forkFinally action (atomically . putTMVar var)
  return (Async t var)

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

sites = ["http://forec.cn",
         "https://ipv6.google.com",
         "https://github.com",
         "https://www.baidu.com",
         "https://cn.bing.com"]

main :: IO ()
main = do
  let
    download url = do
      r <- getURL url 
      return (url, r)
  as <- mapM (async . download) sites
  (url, r) <- waitAny as
  printf "%s was first (%d bytes)\n" url (B.length r)
  mapM_ wait as