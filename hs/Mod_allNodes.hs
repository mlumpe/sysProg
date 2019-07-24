module Mod_allNodes ( allNodes ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_subtree

allNodes :: Tree -> [Node]
allNodes tree | size tree == 0 = []
              | isLeaf tree (root tree) = [root tree]
              | otherwise = [root tree] ++ (helper tree [] 0)

helper :: Tree -> [Node] -> Int -> [Node]
helper tree res i | i==length childs = res
                  | otherwise = helper tree (res ++ (allNodes (subtree tree (get childs i)))) (i+1)
                  where
                   childs = children tree (root tree)