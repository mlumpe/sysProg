module Mod_isomorphism ( isomorphism ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_treeToString
import Data.Char
import Mod_subtree

isomorphism :: Tree -> Tree -> (Map Node Node)
isomorphism tree1 tree2 
 | isIsomorph tree1 tree2 = joinMaps (setImage emptyMap (root tree1) (root tree2)) (isoHelper tree1 tree2 childs1 childs2 emptyMap)
 | otherwise = emptyMap
    where 
     childs1 = (children tree1 (root tree1))
     childs2 = (children tree2 (root tree2))
        
isoHelper :: Tree -> Tree -> [Node] -> [Node] -> (Map Node Node) -> (Map Node Node)
isoHelper tree1 tree2 toMatch1 toMatch2 map 
 | empty toMatch1 = map
 | isIsomorph sub1 sub2 = isoHelper tree1 tree2 (removeFirst toMatch1) (removeFirst toMatch2) (joinMaps map (isomorphism sub1 sub2))
 | otherwise = isoHelper tree1 tree2 toMatch1 shiftMatch2 map
           where
            n1 = first(toMatch1)
            n2 = first(toMatch2)
            sub1 = subtree tree1 n1
            sub2 = subtree tree2 n2
            shiftMatch2 = append (removeFirst toMatch2) (first toMatch2)

isIsomorph :: Tree -> Tree -> Bool
isIsomorph tree1 tree2 
  | isLeaf tree1 (root tree1) && isLeaf tree2 (root tree2) = True
  | length childs1 == length childs2 = isIsomorphChilds tree1 tree2 childs1 childs2 0
  | otherwise = False
    where 
     childs1 = (children tree1 (root tree1))
     childs2 = (children tree2 (root tree2))

isIsomorphChilds :: Tree -> Tree -> [Node] -> [Node] -> Int -> Bool
isIsomorphChilds tree1 tree2 toMatch1 toMatch2 i
 | empty toMatch1 = True
 | i > length toMatch2 = False
 | isIsomorph sub1 sub2 = isIsomorphChilds tree1 tree2 (removeFirst toMatch1) (removeFirst toMatch2) 0
 | otherwise = isIsomorphChilds tree1 tree2 toMatch1 shiftMatch2 (i+1)
           where
            n1 = first(toMatch1)
            n2 = first(toMatch2)
            sub1 = subtree tree1 n1
            sub2 = subtree tree2 n2
            shiftMatch2 = append (removeFirst toMatch2) (first toMatch2)
