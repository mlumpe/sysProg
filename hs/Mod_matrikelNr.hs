module Mod_matrikelNr ( matrikelNr ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_removeDuplicates

matrikelNr :: [Int] -> [Int]
matrikelNr list = matrikelNrHelper list 10

matrikelNrHelper :: [Int] -> Int -> [Int]
matrikelNrHelper list modNr | length (removeDuplicates newList) == length newList = newList
                            | otherwise = matrikelNrHelper list (modNr*10)
                              where
                               newList = map modX list
                               modX a = mod a modNr
