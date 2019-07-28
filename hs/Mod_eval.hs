module Mod_eval ( eval ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

eval :: (Tree, (Map Node String)) -> (Tree, (Map Node String))

eval ast = evalHelper (get22 ast) (get21 ast) 0

evalHelper mapParam tree done
 | done == 1 = (tree, mapParam)
 | otherwise = evalHelper (get33 implyfertig) (get32 implyfertig) (get31 implyfertig)
 where
  nots = inverseOf mapParam "NOT"
  ands = inverseOf mapParam "AND"
  ors = inverseOf mapParam "OR"
  implys = inverseOf mapParam "IMPLY"
  notfertig = checkNots mapParam tree nots 0 1
  andfertig = checkAnds (get33 notfertig) (get32 notfertig) ands 0 (get31 notfertig)
  orfertig = checkOrs (get33 andfertig) (get32 andfertig) ors 0 (get31 andfertig)
  implyfertig = checkImplys (get33 orfertig) (get32 orfertig) implys 0 (get31 orfertig)
 
checkNots mapParam tree nots i done
 | i == length nots = (done, tree, mapParam)
 | sp_not (isLeaf tree child) = checkNots mapParam tree nots (i+1) done
 | imageOf mapParam child == "TRUE" = checkNots (undefine (setImage mapParam notNode "FALSE") child) (removeLeaf tree child) nots (i+1) 0
 | imageOf mapParam child == "FALSE" = checkNots (undefine (setImage mapParam notNode "TRUE") child) (removeLeaf tree child) nots (i+1) 0
 | otherwise = checkNots mapParam tree nots (i+1) done
 where 
  notNode = get nots i
  child = get (children tree notNode) 0
  
checkAnds mapParam tree nodes i done
 | i == length nodes = (done, tree, mapParam)
 | sp_not (isLeaf tree child1) || sp_not (isLeaf tree child2) = checkAnds mapParam tree nodes (i+1) done
 | imageOf mapParam child1 == "TRUE" = checkAnds (undefine (undefine (setImage mapParam node (imageOf mapParam child2)) child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child1 == "FALSE" = checkAnds (undefine (undefine (setImage mapParam node "FALSE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "TRUE" = checkAnds (undefine (undefine (setImage mapParam node (imageOf mapParam child1)) child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "FALSE" = checkAnds (undefine (undefine (setImage mapParam node "FALSE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | otherwise = checkAnds mapParam tree nodes (i+1) done
 where 
  node = get nodes i
  child1 = get (children tree node) 0
  child2 = get (children tree node) 1
  
  
  
checkOrs mapParam tree nodes i done
 | i == length nodes = (done, tree, mapParam)
 | sp_not (isLeaf tree child1) || sp_not (isLeaf tree child2) = checkOrs mapParam tree nodes (i+1) done
 | imageOf mapParam child1 == "TRUE" = checkOrs (undefine (undefine (setImage mapParam node "TRUE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child1 == "FALSE" = checkOrs (undefine (undefine (setImage mapParam node (imageOf mapParam child2)) child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "TRUE" = checkOrs (undefine (undefine (setImage mapParam node "TRUE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "FALSE" = checkOrs (undefine (undefine (setImage mapParam node (imageOf mapParam child1)) child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | otherwise = checkOrs mapParam tree nodes (i+1) done
 where 
  node = get nodes i
  child1 = get (children tree node) 0
  child2 = get (children tree node) 1
  
  
checkImplys mapParam tree nodes i done
 | i == length nodes = (done, tree, mapParam)
 | sp_not (isLeaf tree child1) || sp_not (isLeaf tree child2) = checkImplys mapParam tree nodes (i+1) done
 | imageOf mapParam child1 == "TRUE" = checkImplys (undefine (undefine (setImage mapParam node (imageOf mapParam child2)) child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child1 == "FALSE" = checkImplys (undefine (undefine (setImage mapParam node "TRUE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "TRUE" = checkImplys (undefine (undefine (setImage mapParam node "TRUE") child1) child2) (removeLeaf (removeLeaf tree child1) child2) nodes (i+1) 0
 | imageOf mapParam child2 == "FALSE" = checkImplys (undefine (setImage mapParam node "NOT") child2) (removeLeaf tree child2) nodes (i+1) 0
 | otherwise = checkImplys mapParam tree nodes (i+1) done
 where 
  node = get nodes i
  child1 = get (children tree node) 0
  child2 = get (children tree node) 1