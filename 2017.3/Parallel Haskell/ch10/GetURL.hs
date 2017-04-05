module GetURL (getURL) where

import Network.HTTP.Conduit
import Data.ByteString (ByteString)
import qualified Data.ByteString.Lazy as L
import Control.Applicative

getURL :: String -> IO ByteString
getURL url = L.toStrict <$> simpleHttp url