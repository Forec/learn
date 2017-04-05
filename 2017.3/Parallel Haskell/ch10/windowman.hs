module WindowManager where

import Control.Concurrent.STM
import Control.Concurrent (forkIO, ThreadId)
import Data.Map as Map
import Data.Set as Set
import Data.Maybe
import System.IO

newtype Window = Window Int deriving(Eq, Ord, Show)
newtype Desktop = Desktop Int deriving (Eq, Ord, Show)

type Display = Map Desktop (TVar (Set Window))

insertWindowIntoDesktop :: Display -> Window -> Desktop -> STM ()
insertWindowIntoDesktop disp win desk = do
  wa <- readTVar ma
  writeTVar ma (Set.insert win wa)
  where
    ma = disp ! desk

moveWindowSTM :: Display -> Window -> Desktop -> Desktop -> STM ()
moveWindowSTM disp win a b = do
  wa <- readTVar ma
  wb <- readTVar mb
  writeTVar ma (Set.delete win wa)
  writeTVar mb (Set.insert win wb)
  where
    ma = disp ! a
    mb = disp ! b

moveWindow :: Display -> Window -> Desktop -> Desktop -> IO ()
moveWindow disp win a b = atomically $ moveWindowSTM disp win a b

swapWindows :: Display
            -> Window -> Desktop
            -> Window -> Desktop
            -> IO ()
swapWindows disp w a v b = atomically $ do
  moveWindowSTM disp w a b
  moveWindowSTM disp v b a

render:: Set Window -> IO ()
render wins = print (Set.toList wins)

type UserFocus = TVar Desktop

getWindows :: Display -> UserFocus -> STM (Set Window)
getWindows disp focus = do
  desktop <- readTVar focus
  readTVar (disp ! desktop)

renderThread :: Display -> UserFocus -> IO ()
renderThread disp focus = do
  wins <- atomically $ getWindows disp focus
  loop wins
  where
    loop wins = do
      render wins
      next <- atomically $ do
        wins' <- getWindows disp focus
        if wins == wins' then retry else return wins'
      loop next

[win1, win2, win3, win4] = Prelude.map Window [1, 2, 3, 4]
desktop1 = Desktop 1
desktop2 = Desktop 2

run :: IO (ThreadId, Display)
run = do
  tvar1 <- newTVarIO Set.empty
  tvar2 <- newTVarIO Set.empty
  focus1 <- newTVarIO desktop1
  let disp = Map.fromList [(desktop1, tvar1), (desktop2, tvar2)]
  tid <- forkIO $ renderThread disp focus1
  return (tid, disp)