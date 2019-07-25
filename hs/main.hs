import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_treeToString
import Mod_sizeLogspace
import Mod_nonRecursiveCheck

--Tree t1
t1 = newTree
v11 = root t1

--Tree t2
t2_1 = newTreeOwn (createNode 1)
t2_2 = addOwnLeaf t2_1 (createNode 1) (createNode 2)
t2_3 = addOwnLeaf t2_2 (createNode 1) (createNode 3)
t2_4 = addOwnLeaf t2_3 (createNode 2) (createNode 4)
t2_5 = addOwnLeaf t2_4 (createNode 2) (createNode 5)
t2_6 = addOwnLeaf t2_5 (createNode 5) (createNode 6)
t2_7 = addOwnLeaf t2_6 (createNode 5) (createNode 7)
t2_8 = addOwnLeaf t2_7 (createNode 5) (createNode 8)
t2_9 = addOwnLeaf t2_8 (createNode 3) (createNode 9)
t2 = t2_9


t3_1 = newTreeOwn (createNode 5)
t3_2 = addOwnLeaf t3_1 (createNode 5) (createNode 6)
t3_3 = addOwnLeaf t3_2 (createNode 5) (createNode 7)
t3_4 = addOwnLeaf t3_3 (createNode 5) (createNode 8)
t3 = t3_4


t4_1 = newTreeOwn (createNode 1)
t4_2 = addOwnLeaf t4_1 (createNode 1) (createNode 2)
t4_3 = addOwnLeaf t4_2 (createNode 1) (createNode 3)
t4_4 = addOwnLeaf t4_3 (createNode 2) (createNode 4)
t4_5 = addOwnLeaf t4_4 (createNode 3) (createNode 9)
t4 = t4_5


t5_1 = newTreeOwn (createNode 1)
t5_2 = addOwnLeaf t5_1 (createNode 1) (createNode 3)
t5_3 = addOwnLeaf t5_2 (createNode 3) (createNode 9)
t5 = t5_3


t6_1 = newTreeOwn (createNode 6)
t6_2 = addOwnLeaf t6_1 (createNode 6) (createNode 2)
t6_3 = addOwnLeaf t6_2 (createNode 6) (createNode 9)
t6_4 = addOwnLeaf t6_3 (createNode 2) (createNode 1)
t6_5 = addOwnLeaf t6_4 (createNode 2) (createNode 4)
t6_6 = addOwnLeaf t6_5 (createNode 4) (createNode 18)
t6_7 = addOwnLeaf t6_6 (createNode 4) (createNode 7)
t6_8 = addOwnLeaf t6_7 (createNode 4) (createNode 3)
t6_9 = addOwnLeaf t6_8 (createNode 9) (createNode 5)
t6 = t6_9

t7_1 = newTreeOwn (createNode 1)
t7_2 = addOwnLeaf t7_1 (createNode 1) (createNode 2)
t7_3 = addOwnLeaf t7_2 (createNode 2) (createNode 3)
t7_4 = addOwnLeaf t7_3 (createNode 1) (createNode 4)
t7_5 = addOwnLeaf t7_4 (createNode 4) (createNode 5)
t7_6 = addOwnLeaf t7_5 (createNode 4) (createNode 6)
t7_7 = addOwnLeaf t7_6 (createNode 6) (createNode 7)
t7_8 = addOwnLeaf t7_7 (createNode 1) (createNode 8)
t7_9 = addOwnLeaf t7_8 (createNode 8) (createNode 9)
t7_10 = addOwnLeaf t7_9 (createNode 8) (createNode 10)
t7_11 = addOwnLeaf t7_10 (createNode 10) (createNode 11)
t7_12 = addOwnLeaf t7_11 (createNode 8) (createNode 12)
t7_13 = addOwnLeaf t7_12 (createNode 12) (createNode 13)
t7_14 = addOwnLeaf t7_13 (createNode 13) (createNode 14)
t7 = t7_14


t8_1 = newTreeOwn (createNode 1)
t8_2 = addOwnLeaf t8_1 (createNode 1) (createNode 2)
t8_3 = addOwnLeaf t8_2 (createNode 2) (createNode 3)
t8_4 = addOwnLeaf t8_3 (createNode 3) (createNode 4)
t8_5 = addOwnLeaf t8_4 (createNode 2) (createNode 5)
t8_6 = addOwnLeaf t8_5 (createNode 1) (createNode 6)
t8_7 = addOwnLeaf t8_6 (createNode 6) (createNode 7)
t8_8 = addOwnLeaf t8_7 (createNode 7) (createNode 8)
t8_9 = addOwnLeaf t8_8 (createNode 6) (createNode 9)
t8_10 = addOwnLeaf t8_9 (createNode 9) (createNode 10)
t8_11 = addOwnLeaf t8_10 (createNode 10) (createNode 11)
t8_12 = addOwnLeaf t8_11 (createNode 6) (createNode 12)
t8_13 = addOwnLeaf t8_12 (createNode 1) (createNode 13)
t8_14 = addOwnLeaf t8_13 (createNode 13) (createNode 14)
t8 = t8_14

t9_1 = newTreeOwn (createNode 1)
t9_2 = addOwnLeaf t9_1 (createNode 1) (createNode 2)
t9_3 = addOwnLeaf t9_2 (createNode 2) (createNode 3)
t9_4 = addOwnLeaf t9_3 (createNode 2) (createNode 4)
t9_5 = addOwnLeaf t9_4 (createNode 1) (createNode 5)
t9_6 = addOwnLeaf t9_5 (createNode 5) (createNode 6)
t9_7 = addOwnLeaf t9_6 (createNode 6) (createNode 7)
t9_8 = addOwnLeaf t9_7 (createNode 5) (createNode 8)
t9 = t9_8

t10_1 = newTreeOwn (createNode 1)
t10_2 = addOwnLeaf t10_1 (createNode 1) (createNode 2)
t10_3 = addOwnLeaf t10_2 (createNode 2) (createNode 3)
t10_4 = addOwnLeaf t10_3 (createNode 3) (createNode 4)
t10_5 = addOwnLeaf t10_4 (createNode 1) (createNode 5)
t10_6 = addOwnLeaf t10_5 (createNode 5) (createNode 6)
t10_7 = addOwnLeaf t10_6 (createNode 6) (createNode 7)
t10_8 = addOwnLeaf t10_7 (createNode 5) (createNode 8)
t10 = t10_8

--Code zum Testen der geschriebenen Funktionen

main = do putStrLn ("*** Tests ***")
          putStrLn ("sizeLogspace(t1, v1)")
          putStrLn (show (sizeLogspace t1 (createNode 1)))
          putStrLn ("sizeLogspace(t2, v2)")
          putStrLn (show (sizeLogspace t2 (createNode 2)))
          putStrLn ("sizeLogspace(t4, v3)")
          putStrLn (show (sizeLogspace t4 (createNode 3)))
          putStrLn ("nonRecursiveCheck(t1, t1, v1, v1)")
          putStrLn (show (nonRecursiveCheck t1 t1 (createNode 1) (createNode 1)))
          putStrLn ("nonRecursiveCheck(t3, t2, v5, v1)")
          putStrLn (show (nonRecursiveCheck t3 t2 (createNode 5) (createNode 1)))
          