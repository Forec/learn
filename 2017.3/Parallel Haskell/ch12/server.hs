module Main where

import ConcurrentUtils
import System.IO
import Network
import Control.Monad
import Text.Printf
import Control.Exception
import Control.Concurrent (forkIO)


talk :: Handle -> IO ()
talk h = do
  hSetBuffering h LineBuffering
  loop
 where
  loop = do
    line <- hGetLine h
    if line == "end"
    then hPutStrLn h ("Thank you for using the " ++
                      "Haskell doubling service.")
    else do
     hPutStrLn h (show (2 * (read line :: Integer)))
     loop

port :: Int
port = 44444

main :: IO ()
main = withSocketsDo $ do
  sock <- listenOn (PortNumber (fromIntegral port))
  printf "Listening on port %d\n" port
  forever $ do
    (handle, host, port) <- accept sock
    printf "Accpeted connection from %s:%s\n" host (show port)
    forkFinally (talk handle) (\_ -> hClose handle)