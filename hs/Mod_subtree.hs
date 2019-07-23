module Mod_subtree ( subtree ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

subtree tree node = addChildren tree (newTreeOwn node) node

addChildren orig newTree node = aCHelper orig newTree node 0

aCHelper orig newTree node i 
   | i == length (children orig node) = newTree
   | otherwise = aCHelper orig (addChildren orig (addOwnLeaf newTree node (get (children orig node) i)) (get (children orig node) i)) node (i+1) 