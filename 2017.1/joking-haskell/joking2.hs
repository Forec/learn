module Main where

import System.Environment (getArgs)
import System.IO
import Data.List (delete)
import System.Directory (removeFile, renameFile)

dispatch :: [(String, [String] -> IO ())]
dispatch = [("add", add)
           ,("view", view)
           ,("help", help)
           ,("bump", bump)
           ,("remove", remove)]

main :: IO ()
main = do
  (command : args) <- getArgs
  let (Just action) = lookup command dispatch
  action args

add :: [String] -> IO ()
add [fileName, todoItem] = appendFile fileName ("\n" ++ todoItem)
add _ = putStrLn "Params not valid"

view :: [String] -> IO ()
view [fileName] = do
  contents <- readFile fileName
  let todoTasks = lines contents
      numberedTasks = zipWith (\n line -> show n ++ " - " ++ line) [(0::Int)..] todoTasks
  putStr $ unlines numberedTasks
view _ = putStrLn "Params not vaild"

remove :: [String] -> IO ()
remove [fileName, numberString] = do
  rhandle <- openFile fileName ReadMode
  (tempName, rtempHandle) <- openTempFile "." "temp"
  contents <- hGetContents rhandle
  let number = read numberString :: Int
      todoTasks = lines contents
      newTodoItems = delete (todoTasks !! number) todoTasks
  hPutStr rtempHandle $ unlines newTodoItems
  hClose rhandle
  hClose rtempHandle
  removeFile fileName
  renameFile tempName fileName
remove _ = putStrLn "Params not valid"

help :: [String] -> IO ()
help _ = putStrLn "You can use view/add/remove/help"

bump :: [String] -> IO ()
bump [fileName, numberString] = do
  handle <- openFile fileName ReadMode
  (tempName, tempHandle) <- openTempFile "." "temp"
  contents <- hGetContents handle
  let number = read numberString :: Int
      todoTasks = lines contents
      newTodoItems = todoTasks !! number : delete (todoTasks !! number) todoTasks
  hPutStr tempHandle $ unlines newTodoItems
  hClose handle
  hClose tempHandle
  removeFile fileName
  renameFile tempName fileName
bump _ = putStrLn "Params not valid"