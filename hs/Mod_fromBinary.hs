module Mod_fromBinary ( fromBinary ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

fromBinary bin = fromBinaryHelper bin 0 1

fromBinaryHelper bin res mult 
   |empty bin = res
   |otherwise = fromBinaryHelper (removeLast bin) (res+(last bin)*mult) (mult*2)