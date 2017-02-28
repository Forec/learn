module JokingDiffList(
  DiffList(..),
  toDiffList,
  fromDiffList
) where

newtype DiffList a = DiffList { 
  getDiffList :: [a] -> [a]
}

toDiffList :: [a] -> DiffList a
toDiffList xs = DiffList (xs++)

fromDiffList :: DiffList a -> [a]
fromDiffList (DiffList f) = f []

instance Monoid (DiffList a) where
  mempty = DiffList (\xs -> [] ++ xs)
  (DiffList f) `mappend` (DiffList g) = DiffList (f . g)