{-# LANGUAGE NoImplicitPrelude #-}

module JokingQuickCheck where

import Prelude hiding (reverse)
import Test.QuickCheck

reverse :: [a] -> [a]
reverse = foldr (:) []

prop_TestReverse :: [Int] -> Bool
prop_TestReverse ls = reverse (reverse ls) == ls 

ordered :: (Ord a) => [a] -> Bool
ordered xs = and (zipWith (<=) xs (drop 1 xs))

insert :: (Ord a) => a -> [a] -> [a]
insert x xs = takeWhile (<x) xs ++ [x] ++ dropWhile (<x) xs

prop_TestInsert :: (Ord a) => a -> [a] -> Property
prop_TestInsert x xs = ordered xs ==> ordered (insert x xs)

take5 :: String -> String
take5 = take 5 . filter (`elem` ['a'..'e'])

handyCheck :: Testable a => Int -> a -> IO ()
handyCheck limit = quickCheckWith (stdArgs {maxSuccess = limit})

verboseCheck' :: Testable a => Int -> a -> IO ()
verboseCheck' limit = verboseCheckWith (stdArgs {maxSuccess = limit})

data Tree a = Node (Tree a) (Tree a) | Leaf a deriving (Show, Eq, Ord)

reduce :: (a -> a -> a) -> Tree a -> a
reduce f (Leaf x) = x
reduce f (Node x y) = f (reduce f x) (reduce f y)