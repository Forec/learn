-- fucking homework for fallenwood

curry :: ((a,b) -> c) -> (a -> (b -> c))
curry f x y = f (x, y)

uncurry :: (a -> (b -> c)) -> ((a,b) -> c)
uncurry f (x, y) = f x y
