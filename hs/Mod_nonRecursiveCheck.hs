module Mod_nonRecursiveCheck ( nonRecursiveCheck ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

import Mod_hasNextSibling
import Mod_nextSibling
import Mod_firstChild
import Mod_sizeLogspace

numChildrenInit :: Tree -> Node -> Int
numChildrenInit t n
 | isLeaf t n = 0
 | otherwise = numChildren t (firstChild t n) 1

numChildren :: Tree -> Node -> Int -> Int
numChildren t n cnt
 | hasNextSibling t n = numChildren t (nextSibling t n) (cnt+1)
 | otherwise = cnt
 
countNumberInit :: Tree -> Node -> Int -> Int
countNumberInit t n num
 | sizeLogspace t firstC == num = countNumber t firstC num 1
 | otherwise = countNumber t firstC num 0
    where
     firstC = firstChild t n
 
countNumber :: Tree -> Node -> Int -> Int -> Int
countNumber t n num cnt
 | hasNextSibling t n && sizeLogspace t next == num = countNumber t next num (cnt+1)
 | hasNextSibling t n = countNumber t next num cnt
 | otherwise = cnt
  where
   next = nextSibling t n
 
lexikoLess :: Tree -> Tree -> Node -> Node -> Int -> Int -> Bool
lexikoLess t1 t2 n1 n2 numChilds act
 | numChilds == 0 = False
 | c1>c2 = True
 | c1<c2 = False
 | otherwise = lexikoLess t1 t2 n1 n2 (numChilds-c1) (act+1)
   where
    c1 = countNumberInit t1 n1 act
    c2 = countNumberInit t2 n2 act

nonRecursiveCheck :: Tree -> Tree -> Node -> Node -> Bool
nonRecursiveCheck t1 t2 n1 n2
 | s1<s2 = True
 | s1 == s2 && num1<num2 = True
 | s1 == s2 && num1== num2 && lexikoLess t1 t2 n1 n2 num1 0 = True
 | otherwise = False
   where
    s1 = sizeLogspace t1 n1
    s2 = sizeLogspace t2 n2
    num1 = numChildrenInit t1 n1
    num2 = numChildrenInit t2 n2