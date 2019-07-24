module Mod_isomorphism ( isomorphism ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_treeToString
import Data.Char
import Mod_subtree

isomorphism :: Tree -> Tree -> (Map Node Node)
isomorphism tree1 tree2 | isIsomorph tree1 tree2 = joinMaps (setImage emptyMap (root tree1) (root tree2)) (isoHelper tree1 tree2 0 emptyMap)
                        | otherwise = emptyMap
                        
isoHelper tree1 tree2 i map | i == length (children tree1 (root tree1)) = map
                            | otherwise = isoHelper tree1 tree2 (i+1) (joinMaps map (isomorphism subtree1 subtree2))
                                   where
                                   subtree1 = subtree tree1 (get (children tree1 (root tree1)) i)
                                   subtree2 = subtree tree2 (get (children tree2 (root tree2)) i)

    
isIsomorph tree1 tree2 | isLeaf tree1 (root tree1) && isLeaf tree2 (root tree2) = True
                       | length (children tree1 (root tree1)) == length (children tree2 (root tree2)) = isIsomorphChilds tree1 tree2 0 True
                       | otherwise = False
                       
isIsomorphChilds tree1 tree2 i iso | i == length (children tree1 (root tree1)) = iso
                                   | otherwise = sp_and iso (isIsomorph subtree1 subtree2)
                                   where
                                   subtree1 = subtree tree1 (get (children tree1 (root tree1)) i)
                                   subtree2 = subtree tree2 (get (children tree2 (root tree2)) i)