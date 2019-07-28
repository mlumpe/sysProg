module Mod_parse ( parse ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

import Mod_treeToString


findBoundary :: [(String, String)] -> Int -> (Int, Int)
findBoundary t start
 | token == "VAR" || token == "TRUE" || token == "FALSE" = (start, start)
 | otherwise = findBoundaryHelper t start (start+1) 1
  where
   first = get t start
   token = get21 first

findBoundaryHelper :: [(String, String)] -> Int -> Int -> Int -> (Int, Int)
findBoundaryHelper t start i po
 | po == 0 = (start, (i-1))
 | token == "PO" = (findBoundaryHelper t start (i+1) (po+1))
 | token == "PC" = (findBoundaryHelper t start (i+1) (po-1))
 | otherwise = (findBoundaryHelper t start (i+1) po)
  where
   token = get21 (get t i)

parseRec :: [(String, String)] -> Tree -> Node -> (Map Node String) -> Int -> (Tree, (Map Node String), Int)
parseRec t tree n mapParam idParam 
 | token == "VAR" = (tree, (setImage mapParam n inhalt), idParam)
 | token == "TRUE" || token == "FALSE" = (tree, (setImage mapParam n token), idParam)
 | otherwise = (parseRecElse t tree n mapParam idParam)
 where 
  first = get t 0
  token = get21 first
  inhalt = get22 first
  
parseRecElse t tree n mapParam idParam
 | token == "NOT" = (parseRecFinish t tree n (setImage mapParam n "NOT") idParam 0)
 | otherwise = (parseRecFirst t tree n mapParam idParam)
  where 
   second = get t 1
   token = get21 second
   
parseRecFirst t tree n mapParam idParam = (parseRecFinish t newnewTree n newnewMap newnewID endeErste)
 where
  ersteFormel = findBoundary t 1
  startErste = get21 ersteFormel
  endeErste = get22 ersteFormel
  rootToken = get21 (get t (endeErste+1))
  newMap = setImage mapParam n rootToken
  newRoot1 = createNode idParam
  newTree = addOwnLeaf tree n newRoot1
  teil1 = parseRec (sublist t startErste (endeErste-startErste+1)) newTree newRoot1 newMap (idParam+1)
  newnewTree = get31 teil1
  newnewMap = get32 teil1
  newnewID = get33 teil1
  
parseRecFinish t tree n mapParam idParam  endeErste
 = (parseRec (sublist t startZweite (endeZweite-startZweite+1)) newTree newRoot2 mapParam (idParam+1))
 where
  zweiteFormel = findBoundary t (endeErste+2)
  startZweite = get21 zweiteFormel
  endeZweite = get22 zweiteFormel
  newRoot2 = createNode idParam
  newTree = addOwnLeaf tree n newRoot2

parse :: [(String, String)] -> (Tree, (Map Node String))
parse t = (get31 rec, get32 rec)
 where 
  rec = parseRec t (newTreeOwn root) root emptyMap 2
  root = createNode 1
  