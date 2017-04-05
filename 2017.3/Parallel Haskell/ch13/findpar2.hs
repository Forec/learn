{-# LANGUAGE BangPatterns #-}

import System.Directory
import System.FilePath
import Control.Concurrent.Async
import System.Environment
import Data.List hiding(find)
import Control.Exception (finally)
import Control.Concurrent.MVar

main :: IO ()
main = do
  [n, s, d] <- getArgs
  sem <- newNBSem (read n)
  find sem s d >>= print

find :: NBSem -> String -> FilePath -> IO (Maybe FilePath)
find sem s d = do
  fs <- getDirectoryContents d
  let fs' = sort $ filter (`notElem` [".", ".."]) fs
  if s `elem` fs'
  then return (Just (d </> s))
  else do
    let ps = map (d </>) fs'
    foldr (subfind sem s) dowait ps []
 where
  dowait as = loop (reverse as)
  loop [] = return Nothing
  loop (a:as) = do
    r <- wait a
    case r of 
      Nothing -> loop as
      Just _ -> return r

subfind :: NBSem -> String -> FilePath
        -> ([Async (Maybe FilePath)] -> IO (Maybe FilePath))
        ->  [Async (Maybe FilePath)] -> IO (Maybe FilePath)
subfind sem s p inner asyncs = do
  isdir <- doesDirectoryExist p
  if not isdir
  then inner asyncs
  else do
    q <- tryAcquireNBSem sem
    if q 
    then do
      let dofind = find sem s p `finally` releaseNBSem sem
      withAsync dofind $ \a -> inner (a:asyncs)
    else do
      r <- find sem s p
      case r of 
        Nothing -> inner asyncs
        Just _ -> return r

newtype NBSem = NBSem (MVar Int)

newNBSem :: Int -> IO NBSem
newNBSem i = do
  m <- newMVar i
  return (NBSem m)

tryAcquireNBSem :: NBSem -> IO Bool
tryAcquireNBSem (NBSem m) =
  modifyMVar m $ \i ->
    if i == 0
    then return (i, False)
    else let !z = i-1 in return (z, True)

releaseNBSem :: NBSem -> IO ()
releaseNBSem (NBSem m) = 
  modifyMVar m $ \i ->
    let !z = i + 1 in return (z, ())