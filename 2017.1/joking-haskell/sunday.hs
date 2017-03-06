module SUNDAY where

import Data.List (elemIndex)

sunday :: String -> String -> Int
sunday text pattern' = iter 0 0 0 where
  iter :: Int -> Int -> Int -> Int
  iter i j find
    | j == length pattern' = if i <= length text then find else -1
    | (text !! i) == (pattern' !! j) = iter (i+1) (j+1) find
    | otherwise = iter i' 0 i' where
        last_ :: Char
        last_ = text !! (find + length pattern')
        pos_ = elemIndex last_ pattern'
        toMove = case pos_ of
          Nothing -> length pattern' + 1
          Just x -> length pattern' - x
        i' = i + toMove