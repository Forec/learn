{-# LANGUAGE CPP, MagicHash, UnboxedTuples #-}

module ConcurrentUtils (
  forkFinally
) where

import Control.Concurrent.STM
import Control.Exception
import Control.Concurrent
import Prelude hiding(catch)
import Control.Monad
import Control.Applicative
import GHC.Exts
import GHC.IO hiding(finally)
import GHC.Conc

#if __GLASGOW_HASKELL__ < 706
forkFinally :: IO a -> (Either SomeException a -> IO ()) -> IO ThreadId
forkFinally action and_then = 
  mask $ \restore ->
    forkIO $ try (restore action) >>= and_then
#endif