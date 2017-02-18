module Main where

import System.Random
import System.IO (hFlush, stdout)
import Control.Monad (unless)

main :: IO ()
main = do
  gen <- getStdGen
  askForNum gen
  where
    askForNum :: StdGen -> IO ()
    askForNum generator = do
      let (number, newGen) = randomR (1, 10) generator :: (Int, StdGen)
      putStr "Which number in range 1 to 10 am I thinking of ? "
      hFlush stdout
      numberString <- getLine
      unless (null numberString) $ do
        if (read numberString:: Int) == number
        then putStrLn "You are correct!"
        else  putStrLn ("Sorry, it was " ++ show number)
        askForNum newGen