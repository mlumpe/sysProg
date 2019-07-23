module Mod_toBinary ( toBinary ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

toBinary :: Int -> [Int]
toBinary from | from == 0 = [0]
              | otherwise = toBinaryHelper from []

toBinaryHelper from res 
   | from == 0 = res
   | otherwise = toBinaryHelper (sp_div from 2) (prepend res (sp_mod from 2))