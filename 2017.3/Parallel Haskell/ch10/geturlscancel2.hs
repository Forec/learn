{-# LANGUAGE DeriveDataTypeable, CPP #-}

import GetURL
import TimeIt
import Data.Either
import Control.Monad
import System.IO
import Control.Concurrent hiding(forkFinally)

import Control.Exception
import Text.Printf
import qualified Data.ByteString as B
import Data.Typeable
import Prelude hiding (catch)

data Async a = Async ThreadId (MVar (Either SomeException a))

forkFinally :: IO a -> (Either SomeException a -> IO ()) -> IO ThreadId
forkFinally action fun = 
  mask $ \restore ->
    forkIO (do r <- try (restore action); fun r)

async :: IO a -> IO (Async a)
async action = do
  m <- newEmptyMVar
  t <- forkFinally action (putMVar m)
  return (Async t m)

waitCatch :: Async a -> IO (Either SomeException a)
waitCatch (Async _ var) = readMVar var

wait :: Async a -> IO a
wait m = do
  r <- waitCatch m
  case r of
    Left e -> throwIO e
    Right a -> return a

cancel :: Async a -> IO ()
cancel (Async t var) = throwTo t ThreadKilled

sites = ["http://forec.cn",
         "https://cn.bing.com",
         "https://www.baidu.com",
         "https://ipv6.google.com"]

timeDownload :: String -> IO ()
timeDownload url = do
  (page, time) <- timeit $ getURL url
  printf "downloaded: %s (%d bytes, %.2fs)\n" url (B.length page) time

main = do
  as <- mapM (async . timeDownload) sites
  forkIO $ do
    hSetBuffering stdin NoBuffering
    forever $ do
      c <- getChar
      when (c == 'q') $ mapM_ cancel as
  rs <- mapM waitCatch as
  printf "%d/%d succeeded\n" (length (rights rs)) (length rs)