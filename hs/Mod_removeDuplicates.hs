module Mod_removeDuplicates ( removeDuplicates ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

removeDuplicates  :: (Eq a) => [a] -> [a]
removeDuplicates input = rDHelper input [] 0

rDHelper :: (Eq a) => [a] -> [a] -> Int -> [a]
rDHelper inp out i | i < length(inp) && contains out act = rDHelper inp out (i+1)
				   | i < length(inp) = rDHelper inp (out++[act]) (i+1)
				   | otherwise = out
				 	  where
					     act = get inp i