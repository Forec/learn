module Main where

import Data.List (intersperse)
import Data.Char (toUpper)

main :: IO ()
main = do line <- fmap (intersperse '-' . map toUpper . reverse) getLine
          putStrLn line

-- functor laws
-- fmap id = id
-- fmap (f . g) = fmap f . fmap g
-- 一个型别遵守 functor laws 则可以对其做基本的假设。遵守 functor laws 说明对其做 fmap 不会产生多余的事情，
-- 而仅仅是一个函数映射。这使写出来的代码足够抽象，并且容易扩展。


-- applicative laws
-- pure f <*> x = fmap f x