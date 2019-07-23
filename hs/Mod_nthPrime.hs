module Mod_nthPrime ( nthPrime ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

primzahlen = 2 : [n | n <- [3..], prim n primzahlen]
prim n (p:xs)   | p*p > n           = True
                | n `mod` p == 0    = False
                | otherwise         = prim n xs

nthPrime :: Int -> Int
nthPrime n = primzahlen!!(n-1)
