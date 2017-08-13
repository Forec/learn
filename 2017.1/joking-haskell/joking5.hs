module Main where
import System.IO

main :: IO ()
main = do
  hSetBuffering stdin $ BlockBuffering (Just 2048)
  readAndPrint 
  where 
    readAndPrint :: IO ()
    readAndPrint = do
      c <- getChar
      putChar c
      readAndPrint