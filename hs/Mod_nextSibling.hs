module Mod_nextSibling ( nextSibling ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

nextSibling tree node = get (children tree (parent tree node)) ((findIndex tree node 0)+1)

findIndex tree node i | get (childs) i == node = i
                      | otherwise = findIndex tree node (i+1)
                    where
                     childs = children tree (parent tree node)