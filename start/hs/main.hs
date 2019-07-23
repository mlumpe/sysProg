import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme
import Mod_fizzBuzz
import Mod_toBinary
import Mod_fromBinary
import Mod_addBinary
import Mod_multBinary


--Code zum Testen der geschriebenen Funktionen 

main = do putStrLn ("*** Tests ***")     
          putStrLn "addBinary [0],[0]" 
          putStrLn (show (addBinary [0] [0]) )
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