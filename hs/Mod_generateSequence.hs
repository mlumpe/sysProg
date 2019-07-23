module Mod_generateSequence ( generateSequence ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

generateSequence :: (Int -> a) -> Int -> [a]
generateSequence f n = gSH f n 1 []

gSH f n i res | i > n = res
              | otherwise = gSH f n (i+1) (append res (f i))