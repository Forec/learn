module Main where

import System.Random

main :: IO ()
main = do
  gen <- getStdGen
  output $ randomRs ('a', 'z') gen
  where
    output :: String -> IO ()
    output xs = do
      let (part1, part2) = splitAt 20 xs
      putStrLn part1
      output part2