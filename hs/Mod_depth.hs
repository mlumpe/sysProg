module Mod_depth ( depth ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_subtree

depth :: Tree -> Int
depth tree = depthHelper tree 0

depthHelper :: Tree -> Int -> Int
depthHelper tree i | isLeaf tree (root tree) = i
                   | otherwise = depthChilds tree (i+1) 0 0
		
depthChilds :: Tree -> Int -> Int -> Int -> Int
depthChilds tree i j max | j == length childs = max
                         | otherwise = depthChilds tree i (j+1) (sp_max max (depthHelper (subtree tree (get childs j)) i))
                         where
                          childs = children tree (root tree)