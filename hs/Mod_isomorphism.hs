module Mod_isomorphism ( isomorphism ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_treeToString
import Data.Char

isomorphism :: Tree -> Tree -> (Map Node Node)
isomorphism tree1 tree2 = isoString (treeToString tree1) (treeToString tree2) emptyMap

isoString t1 t2 mapO 
    | empty t1 && empty t2 = mapO
	| empty t1 || empty t2 = emptyMap
	| isDigit (first t1) && isDigit (first t2) = isoString (removeFirst t1) (removeFirst t2) (setImage mapO (first t1) (first t2))
	| first t1 == first t2 = isoString (removeFirst t1) (removeFirst t2) mapO
	| otherwise = emptyMap