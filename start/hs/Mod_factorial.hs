module Mod_factorial ( factorial ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)
