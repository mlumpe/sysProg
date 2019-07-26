module Mod_lindell ( lindell ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

import Mod_sizeLogspace
import Mod_nonRecursiveCheck
import Mod_hasNextSibling
import Mod_nextSibling
import Mod_firstChild


trace' :: String -> a -> a
--trace' str x = (trace str x) 
trace' str x = x

kBlockSize :: Tree -> Node -> Int -> (Bool, Node)
kBlockSize t v minK = kBlockSizeHelper t v minK (firstChild t v) (firstChild t v) (sizeLogspace t v) False

kBlockSizeHelper :: Tree -> Node -> Int -> Node -> Node -> Int -> Bool -> (Bool, Node)
kBlockSizeHelper t v minK kid resKid res found
 | kidSize > minK && kidSize < res && nextPossible = kBlockSizeHelper t v minK next kid kidSize True
 | kidSize > minK && kidSize < res = (True, kid)
 | nextPossible = kBlockSizeHelper t v minK next resKid res found
 | otherwise = (found, resKid)
    where 
     kidSize = sizeLogspace t kid
     nextPossible = hasNextSibling t kid
     next = nextSibling t kid

lindell :: Tree -> Tree -> Int
lindell s t = trace' "u;v;k;res" (lindellHelper s t 0 0 (root s) (root t))

lindellHelper :: Tree -> Tree -> Int -> Int -> Node -> Node -> Int
lindellHelper s t res k actU actV 
 | res /= 0 && isRoot s actU = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) res
 | res /= 0 = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t res newK parU parV)
 | nonRecursiveCheck s t actU actV = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t (-1) k actU actV)
 | nonRecursiveCheck t s actV actU = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t 1 k actU actV)
 | isLeaf s actU && isLeaf t actV && isRoot s actU = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) 0
 | isLeaf s actU && isLeaf t actV = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t 0 newK parU parV)
 | nextPossible = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t res 0 ku kv)
 | isRoot s actU = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) res
 | otherwise = trace' ((show actU) ++ ";" ++ (show actV) ++ ";" ++ (show k) ++ ";" ++ (show res)) (lindellHelper s t res newK parU parV)
   where 
    newK = sizeLogspace s actU
    parU = parent s actU
    parV = parent t actV
    ku = get22 (kBlockSize s actU k)
    kv = get22 (kBlockSize t actV k)
    nextPossible = get21 (kBlockSize s actU k)