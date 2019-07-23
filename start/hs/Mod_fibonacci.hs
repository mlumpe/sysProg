module Mod_fibonacci ( fibonacci ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)
