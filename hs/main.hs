import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_absolute
import Mod_factorial
import Mod_fibonacci
import Mod_isPrime
import Mod_nthPrime
import Mod_toBinary
import Mod_fromBinary
import Mod_addBinary
import Mod_multBinary
import Mod_addKAry


--Code zum Testen der geschriebenen Funktionen
--Tree t1
t1 = newTree
v11 = root t1

--Tree t2
t2 = newTree
v21 = root t2
t2 = addLeaf t2 v21
t2 = addLeaf t2 v21
v22 = get (children t2 v21) 0
v23 = get (children t2 v21) 1
t2 = addLeaf t2 v22
t2 = addLeaf t2 v22
v24 = get (children t2 v21) 0
v25 = get (children t2 v21) 1
t2 = addLeaf t2 v25
t2 = addLeaf t2 v25
t2 = addLeaf t2 v25
v26 = get (children t2 v25) 0
v27 = get (children t2 v25) 1
v28 = get (children t2 v25) 2
t2 = addLeaf t2 v23
v29 = get (children t2 v23) 0

main = do putStrLn ("*** Tests ***")
          putStrLn ("absolute -3: ")
          putStrLn (show (absolute (-3)))
          putStrLn ("absolute 2: ")
          putStrLn (show (absolute (2)))
          putStrLn ("absolute 0: ")
          putStrLn (show (absolute (0)))
          putStrLn ("factorial 0: ")
          putStrLn (show (factorial (0)))
          putStrLn ("factorial 1: ")
          putStrLn (show (factorial (1)))
          putStrLn ("factorial 4: ")
          putStrLn (show (factorial (4)))
          putStrLn ("factorial 5: ")
          putStrLn (show (factorial (5)))
          putStrLn ("fibonacci 0:")
          putStrLn (show (fibonacci (0)))
          putStrLn ("fibonacci 1:")
          putStrLn (show (fibonacci (1)))
          putStrLn ("fibonacci 2:")
          putStrLn (show (fibonacci (2)))
          putStrLn ("fibonacci 3:")
          putStrLn (show (fibonacci (3)))
          putStrLn ("fibonacci 6:")
          putStrLn (show (fibonacci (6)))
          putStrLn ("isPrime 0:")
          putStrLn ( show ( isPrime 0) )
          putStrLn ("isPrime 1:")
          putStrLn ( show ( isPrime 1) )
          putStrLn ("isPrime 2:")
          putStrLn ( show ( isPrime 2) )
          putStrLn ("isPrime 3:")
          putStrLn ( show ( isPrime 3) )
          putStrLn ("isPrime 4:")
          putStrLn ( show ( isPrime 4) )
          putStrLn ("isPrime 17:")
          putStrLn ( show ( isPrime 17) )
          putStrLn ("nthPrime 1")
          putStrLn (show ( nthPrime 1))
          putStrLn ("nthPrime 2")
          putStrLn (show ( nthPrime 2))
          putStrLn ("nthPrime 3")
          putStrLn (show ( nthPrime 3))
          putStrLn ("nthPrime 10")
          putStrLn (show ( nthPrime 10))
          putStrLn "addBinary [0],[0]"
          putStrLn (show (addBinary [0] [0]) )
          putStrLn "addBinary [1],[1]"
          putStrLn (show (addBinary [1] [1]) )
          putStrLn "addBinary [1,0,0,1],[1,1,0]"
          putStrLn (show (addBinary [1,0,0,1] [1,1,0]) )
          putStrLn "addBinary [1,1,1],[1,1,1]"
          putStrLn (show (addBinary [1,1,1] [1,1,1]) )
          putStrLn "addBinary [1,1,1],[1,0,1,1]"
          putStrLn (show (addBinary [1,1,1] [1,0,1,1]) )
          putStrLn "addBinary [1,0,1,1],[1,1,1]"
          putStrLn (show (addBinary [1,0,1,1] [1,1,1]) )
          putStrLn "addBinary [1,0,0],[1,1]"
          putStrLn (show (addBinary [1,0,0] [1,1]) )
          putStrLn "addBinary [1,0,1,1],[1,1,1,0]"
          putStrLn (show (addBinary [1,0,1,1] [1,1,1,0]) )
          putStrLn ""
          putStrLn "multBinary [0],[0]"
          putStrLn (show (multBinary [0] [0]) )
          putStrLn "multBinary [1],[1]"
          putStrLn (show (multBinary [1] [1]) )
          putStrLn "multBinary [1,0,1,1],[1,1,1,0]"
          putStrLn (show (multBinary [1,0,1,1] [1,1,1,0]) )
          putStrLn ""
          putStrLn "toBinary 0"
          putStrLn (show (toBinary 0) )
          putStrLn "toBinary 1"
          putStrLn (show (toBinary 1) )
          putStrLn "toBinary 2"
          putStrLn (show (toBinary 2) )
          putStrLn "toBinary 3"
          putStrLn (show (toBinary 3) )
          putStrLn "toBinary 4"
          putStrLn (show (toBinary 4) )
          putStrLn "toBinary 20"
          putStrLn (show (toBinary 20) )
          putStrLn ""
          putStrLn "fromBinary [0]"
          putStrLn (show (fromBinary [0]) )
          putStrLn "fromBinary [1]"
          putStrLn (show (fromBinary [1]) )
          putStrLn "fromBinary [1,0]"
          putStrLn (show (fromBinary [1,0]) )
          putStrLn "fromBinary [1,1]"
          putStrLn (show (fromBinary [1,1]) )
          putStrLn "fromBinary [1,0,0]"
          putStrLn (show (fromBinary [1,0,0] ))
          putStrLn "fromBinary [1,0,1,0,0]"
          putStrLn (show (fromBinary [1,0,1,0,0]) )
          putStrLn "addKAry 10 [1,2,3] [9,7]"
          putStrLn (show (addKAry 10 [1,2,3] [9,7]))
          putStrLn "addKAry 16 [15,1,3] [9,4,12,0]"
          putStrLn (show (addKAry 16 [15,1,3] [9,4,12,0]))
          putStrLn (show (addKAry 2 [0] [0]))
          putStrLn (show (addKAry 2 [1] [1]))
          putStrLn (show (addKAry 2 [1,0,0,1] [1,1,0]))
          putStrLn (show (addKAry 2 [1,1,1] [1,1,1]))
          putStrLn (show (addKAry 2 [1,1,1] [1,0,1,1]))
          putStrLn (show (addKAry 2 [1,0,1,1] [1,1,1]))
          putStrLn (show (addKAry 10 [1,2,3,4,5,6,7,8,9,0] [4,3,2,0,9,9,9]))
          putStrLn (show (addKAry 16 [15,10,3,15,2,0] [2,15,14,0,1]))
