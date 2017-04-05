module TimeIt (timeit) where

import Data.Time

timeit :: IO a -> IO (a, Double)
timeit io = do
  t0 <- getCurrentTime
  a <- io
  t1 <- getCurrentTime
  return (a, realToFrac (t1 `diffUTCTime` t0))