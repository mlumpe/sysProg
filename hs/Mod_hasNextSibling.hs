module Mod_hasNextSibling ( hasNextSibling ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

hasNextSibling tree node | isRoot tree node = False
                         | childs == index+1 = False
                         | otherwise = true
                           where 
                            childs = length (children tree (parent tree node))
                            index = (findIndex tree node 0)

findIndex tree node i | get (childs) i == node = i
                      | otherwise = findIndex tree node (i+1)
                       where
                         childs = children tree (parent tree node)