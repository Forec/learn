{-# LANGUAGE NoImplicitPrelude #-}
module Monads where

import Prelude hiding (Monad, Maybe(..))

class Monad m where
  return :: a -> m a
  (>>=) :: m a -> (a -> m b) -> m b

newtype Identity a = Identity a

data Maybe a = Nothing | Just a
  deriving (Show, Eq)

newtype State s a = State{runState :: s -> (a, s)}

newtype Reader s a = Reader{runReader :: s -> a}

newtype Writer w a = Writer{runWriter :: (w, a)}

instance Monad Identity where
  return = Identity
  (Identity v) >>= f = f v

instance Monad Maybe where
  return = Just
  Nothing >>= _ = Nothing
  (Just v) >>= f = f v

instance Monad (State s) where
  return x = State $ \s -> (x, s)
  (State h) >>= f = State $ \s -> let (a, newState) = h s
                                      (State  g) = f a
                                  in g newState

instance Monad (Reader s) where
  return x = Reader (const x)
  m >>= k = Reader $ \r -> runReader (k (runReader m r)) r

instance Monoid w => Monad (Writer w) where
  return x = Writer (mempty, x)
  (Writer (v, x)) >>= f = let (Writer (v', y)) = f x in Writer (mappend v v', y)