import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_nextSibling
import Mod_subtree
import Mod_treeToString


--Code zum Testen der geschriebenen Funktionen
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

main = do putStrLn ("*** Tests ***")
          putStrLn ("nextSibling t2 v6")
          putStrLn (show (nextSibling t2 (createNode 6)))
          putStrLn ("nextSibling t2 v7")
          putStrLn (show (nextSibling t2 (createNode 7)))
          putStrLn ("nextSibling t2 v4")
          putStrLn (show (nextSibling t2 (createNode 4)))
          putStrLn ("treeToString t1")
          putStrLn (treeToString t1)
          putStrLn ("treeToString t2")
          putStrLn (treeToString t2)
          putStrLn ("treeToString t3")
          putStrLn (treeToString t3)
          putStrLn ("treeToString t4")
          putStrLn (treeToString t4)
          putStrLn ("treeToString t5")
          putStrLn (treeToString t5)
          putStrLn ("treeToString t6")
          putStrLn (treeToString t6)
          
