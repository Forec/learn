{-# OPTIONS_GHC -Wall #-}
import System.Directory
import System.FilePath
import System.Environment
import Data.List hiding(find)

main :: IO ()
main = do
  [s, d] <- getArgs
  r <- find s d
  print r

find :: String -> FilePath -> IO (Maybe FilePath)
find s d = do
  fs <- getDirectoryContents d
  let fs' = sort $ filter (`notElem` [".", ".."]) fs
  if s `elem` fs'
  then return (Just (d </> s))
  else loop fs'
 where
  loop [] = return Nothing
  loop (f: fs) = do
    let d' = d </> f
    isdir <- doesDirectoryExist d'
    if isdir 
    then do r <- find s d'
            case r of
              Just _ -> return r
              Nothing -> loop fs
    else loop fs

find' :: String -> FilePath -> IO [FilePath]
find' s d = do
  fs <- getDirectoryContents d
  let fs' = sort $ filter (`notElem` [".", ".."]) fs
  (recurssiveMatch, _) <- foldl' dealJoin (return ([], d)) fs'
  return recurssiveMatch
 where
    dealJoin :: IO ([FilePath], FilePath) -> String -> IO ([FilePath], FilePath)
    dealJoin tuple name = do
      (acc, root) <- tuple
      if s == name then return ((root </> name):acc, root)
      else do
        let path = root </> name
        isdir <- doesDirectoryExist path
        if isdir then do
          rec <- find' s path
          return (rec++acc, root)
        else return (acc, root)
