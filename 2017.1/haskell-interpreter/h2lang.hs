-- h2lang Interpreter

module H2Lang
(   Exp (..)
  , h2
  , runTests
) where

import Data.Maybe (fromMaybe)

data Exp = Value Float       |
           Boolean Bool      |
           String' String    |
           Param String      |
           Error String      |
           Op String Exp Exp |
           Lambda Exp Exp    |
           If Exp Exp Exp    |
           Let Exp Exp Exp   |
           Closure Exp Env   |
           Call Exp Exp deriving (Show)
type Env = [(String, Exp)]

extEnv :: String -> Exp -> Env -> Env
extEnv x v env = (x, v) : env

interp :: Exp -> Env -> Exp
interp (Param x) env = fromMaybe (Error ("undefined variable" ++ x)) (lookup x env)
interp (Value x) _ = Value x
interp (Boolean x) _ = Boolean x
interp (String' x) _ = String' x
interp s@(Lambda _ _) env = Closure s env
interp (Let (Param x) e1 e2) env = interp e2 (extEnv x (interp e1 env) env)
interp (Op op e1 e2) env = let v1 = interp e1 env
                               v2 = interp e2 env
                           in calc op v1 v2
interp (If cond e1 e2) env = let c = interp cond env
                             in case c of
                               Error _       -> Error "syntax error"
                               Boolean False -> interp e2 env
                               _             -> interp e1 env
interp (Call e1 e2) env = case v2 of 
                            Value _   -> callExp
                            Boolean _ -> callExp
                            String' _ -> callExp
                            _         -> Error "syntax error"
    where 
      v2 = interp e2 env
      col = interp e1 env
      callExp = case col of
                (Closure (Lambda (Param x) e) env') -> interp e (extEnv x v2 env')
                _                                   -> Error "syntax error"

calc :: String -> Exp -> Exp -> Exp
calc "+" (Value v1') (Value v2')      = Value (v1' + v2')
calc "-" (Value v1') (Value v2')      = Value (v1' - v2')
calc "*" (Value v1') (Value v2')      = Value (v1' * v2')
calc "/" (Value v1') (Value v2')      = Value (v1' / v2')
calc "<=" (Value v1') (Value v2')     = Boolean (v1' <= v2')
calc ">=" (Value v1') (Value v2')     = Boolean (v1' >= v2')
calc "<" (Value v1') (Value v2')      = Boolean (v1' < v2')
calc ">" (Value v1') (Value v2')      = Boolean (v1' > v2')
calc "==" (Value v1') (Value v2')     = Boolean (v1' == v2')
calc "/=" (Value v1') (Value v2')     = Boolean (v1' /= v2')
calc "&&" (Boolean v1') (Boolean v2') = Boolean (v1' && v2')
calc "||" (Boolean v1') (Boolean v2') = Boolean (v1' || v2')
calc "<" (Boolean v1') (Boolean v2')  = Boolean (v1' < v2')
calc ">" (Boolean v1') (Boolean v2')  = Boolean (v1' > v2')
calc "<=" (Boolean v1') (Boolean v2') = Boolean (v1' <= v2')
calc ">=" (Boolean v1') (Boolean v2') = Boolean (v1' >= v2')
calc "==" (Boolean v1') (Boolean v2') = Boolean (v1' == v2')
calc "/=" (Boolean v1') (Boolean v2') = Boolean (v1' == v2')
calc "==" (String' v1') (String' v2') = Boolean (v1' == v2')
calc "/=" (String' v1') (String' v2') = Boolean (v1' /= v2')
calc "++" (String' v1') (String' v2') = String' (v1' ++ v2')
calc "<" (String' v1') (String' v2')  = Boolean (v1' < v2')
calc ">" (String' v1') (String' v2')  = Boolean (v1' > v2')
calc "<=" (String' v1') (String' v2') = Boolean (v1' <= v2')
calc ">=" (String' v1') (String' v2') = Boolean (v1' >= v2')
calc _ _ _ = Error "syntax error"             

h2 :: Exp -> Exp
h2 = flip interp []

tests :: [Exp]
tests = [h2 (Let (Param "x") (Value 2) 
              (Let (Param "f") (Lambda (Param "y") (Op "*" (Param "x") (Param "y")))
                (Let (Param "x") (Value 4)
                  (Call (Param "f") (Value 3))))),
         h2 (Let (Param "x") (Value 3.9) (Op "/" (Param "x") (Value 4.32))),
         h2 (Let (Param "x") (Value 8.75) (Op ">=" (Param "x") (Value 7))),
         h2 (Op "==" (Boolean True) (Boolean False)),
         h2 (Op "++" (String' "test") (String' " case")),
         h2 (If (Op ">=" (Value 2.3) (Value (-2.754))) (String' "Yes") (String' "No"))
        ]
run :: [Exp] -> IO ()
run [] = return ()
run (x:xs) = do
  print x
  run xs

runTests :: IO ()
runTests = run tests