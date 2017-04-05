import System.Directory
import System.FilePath
import Control.Concurrent.Async
import System.Environment
import Data.List hiding(find)

main :: IO ()
main = do
  [s, d] <- getArgs
  find s d >>= print

find :: String -> FilePath -> IO (Maybe FilePath)
find s d = do
  fs <- getDirectoryContents d
  let fs' = sort $ filter (`notElem` [".", ".."]) fs
  if s `elem` fs'
  then return (Just (d </> s))
  else do
    let ps = map (d </>) fs'
    foldr (subfind s) dowait ps []
 where
  dowait as = loop (reverse as)
  loop [] = return Nothing
  loop (a:as) = do
    r <- wait a
    case r of
      Nothing -> loop as
      Just _ -> return r

subfind :: String -> FilePath
        -> ([Async (Maybe FilePath)] -> IO (Maybe FilePath))
        ->  [Async (Maybe FilePath)] -> IO (Maybe FilePath)
subfind s p inner asyncs = do
  isdir <- doesDirectoryExist p
  if not isdir
  then inner asyncs
  else withAsync (find s p) $ \a -> inner (a: asyncs)