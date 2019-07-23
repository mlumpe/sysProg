module Mod_isPrime ( isPrime ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime 2 = True
isPrime n | (length [x | x <- [2 .. n-1], mod n x == 0]) > 0 = False
		   | otherwise = True
