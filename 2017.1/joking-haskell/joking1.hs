module Main where 

import Data.List (delete)
import System.IO (readFile, hFlush, stdout)
import System.Environment (getProgName)
import Control.Monad (forM_, unless)

main :: IO()
main = do
  contents <- readFile "todolist.txt"
  progName <- getProgName
  putStrLn progName
  readAndDelete contents
  where
    readAndDelete :: String -> IO ()
    readAndDelete contents = do
      let each = lines contents
          lists = zipWith (\n line -> show n ++ " - " ++ line) [(0::Int)..] each
      putStrLn "Your to do list are:"
      hFlush stdout
      forM_ lists putStrLn
      putStr "Please input the number of item you want to delete: "
      hFlush stdout
      number <- getLine
      unless (number == "") $ do
        let readNumber = read number :: Int
        if readNumber >= length each || readNumber < 0
        then do
          putStrLn "Invalid Input!" 
          readAndDelete contents
        else do
          let deletedContents = unlines . delete (each !! (read number::Int)) $ each
          readAndDelete deletedContents