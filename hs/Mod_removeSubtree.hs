module Mod_removeSubtree ( removeSubtree ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_allNodes
import Mod_subtree

removeSubtree :: Tree -> Node -> Tree
removeSubtree tree node = removeNodes tree (allNodes (subtree tree node)) (size tree) 

removeNodes :: Tree -> [Node] -> Int -> Tree
removeNodes tree nodes sizeO | empty nodes = tree
                             | size newTree < sizeO = removeNodes newTree (removeLast nodes) (sizeO-1)
                             | otherwise = removeNodes newTree (prepend (removeLast nodes) lastN) sizeO
                     where 
                       newTree = removeLeaf tree (last nodes)
                       lastN = last nodes