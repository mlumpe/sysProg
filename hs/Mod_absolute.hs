module Mod_absolute ( absolute ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

absolute :: Int -> Int
absolute x  | x < 0 = -x
            | x >= 0 = x
