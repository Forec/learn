module ReaderMonad where

instance Monad ((->) r) where
  return = const
  g >>= f = \w -> f (g w) w

addStuff :: Int -> Int
addStuff = do
  a <- (*2)
  b <- (+10)
  return (a+b)

-- m >>= f >>= g <--> m >>= (\x -> f x >>= g)
-- do <--> >>
-- m >> k = m >>= \_ -> k