module Main where

import System.Environment (getArgs)
import System.IO (readFile)
import System.IO.Error (catchIOError, isDoesNotExistError, ioError, ioeGetFileName)

main :: IO ()
main = catchIOError toTry handler

toTry :: IO ()
toTry = do (fileName : _) <- getArgs
           contents <- readFile fileName
           putStrLn $ "The file has " ++ show (length (lines contents)) ++ " lines."

handler :: IOError -> IO ()
handler e 
  | isDoesNotExistError e = 
      case ioeGetFileName e of Just path -> putStrLn $ "Whoops, file doesn't exist at " ++ path
                               Nothing   -> putStrLn "Whoops, file doesn't exist at unknown path"
  | otherwise = do
      putStrLn "Some unknown error!"
      ioError e