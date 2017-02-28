module JokingWriterMonad where

import Control.Monad.Writer
import JokingDiffList (DiffList, toDiffList, fromDiffList)

multWithLog :: Writer [String] Int
multWithLog = do
  a <- return 3 :: Writer [String] Int
  tell ["This is 3"]
  b <- return 4 :: Writer [String] Int
  tell ["This is 4"]
  return (a*b)

gcd' :: Int -> Int -> Writer [String] Int
gcd' a b
  | a < b = gcd' b a
  | b == 0 = do
      tell ["Finish with gcd = " ++ show a]
      return a
  | otherwise = do
      tell [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)]
      gcd' b (a `mod` b)

gcd'' :: Int -> Int -> Writer (DiffList String) Int
gcd'' a b
  | a < b = gcd'' b a
  | b == 0 = do
      tell (toDiffList ["Finish with gcd = " ++ show a])
      return a
  | otherwise = do
      result <- gcd'' b (a `mod` b)
      tell (toDiffList [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)])
      return result

finalCountDown :: Int -> Writer (DiffList String) ()
finalCountDown 0 = tell (toDiffList ["0"])
finalCountDown x = do
  finalCountDown (x-1)
  tell (toDiffList [show x])  

finalCountDown' :: Int -> Writer [String] ()
finalCountDown' 0 = tell ["0"]
finalCountDown' x = do
  finalCountDown' (x-1)
  tell [show x]

test :: IO ()
test = mapM_ putStrLn . fromDiffList . snd . runWriter $ finalCountDown 100000

test' :: IO ()
test' = mapM_ putStrLn . snd. runWriter $ finalCountDown' 100000