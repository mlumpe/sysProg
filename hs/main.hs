import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_matrikelNr
import Mod_flood
import Mod_stream
import Mod_vier


--Code zum Testen der geschriebenen Funktionen

main = do putStrLn ("*** Tests ***")
          putStrLn ("matrikelNr [123,125,127]")
          putStrLn (show (matrikelNr [123,125,127]))
          putStrLn ("matrikelNr [6123,243,125]")
          putStrLn (show (matrikelNr [6123,243,125]))
          putStrLn ("flood wbwbwbbwbwbw 3 1 2")
          putStrLn (show (flood "wbwbwbbwbwbw" 3 1 2))
          putStrLn ("flood bbwwbw 3 1 0")
          putStrLn (show (flood "bbwwbw" 3 1 0))
          putStrLn ("flood bbbbbbbbwwwbwwwbwwwbwwwb 4 3 4")
          putStrLn (show (flood "bbbbbbbbwwwbbwwbbwwbbwwb" 4 3 4))
          putStrLn ("vier [0,0,-1,1,-2,3,-3]")
          putStrLn (show (vier [0,0,-1,1,-2,3,-3]))
          putStrLn ("vier [-5,2,-4,2,-3,2,-1,2]")
          putStrLn (show (vier [-5,2,-4,2,-3,2,-1,2]))
          putStrLn ("vier [0,1]")
          putStrLn (show (vier [0,1]))
          putStrLn ("vier [0,-3,-3,-2,-2,-1,0,1,-3,-1,-2,-3,-3,-3,-2,-2,-1]")
          putStrLn (show (vier [0,-3,-3,-2,-2,-1,0,1,-3,-1,-2,-3,-3,-3,-2,-2,-1]))
          putStrLn ("vier [-1,-2,3,-1,0,0,1,2,1,0,1,1]")
          putStrLn (show (vier [-1,-2,3,-1,0,0,1,2,1,0,1,1]))
          putStrLn ("vier [-1,-1,0,0,-4,3,-1,-2,3,-2,1,1]")
          putStrLn (show (vier [-1,-1,0,0,-4,3,-1,-2,3,-2,1,1]))
          putStrLn ("stream abc d")
          putStrLn (show (stream "abc" "d"))
          putStrLn ("stream aaaa aa")
          putStrLn (show (stream "aaaa" "aa"))
          putStrLn ("stream caaca *a")
          putStrLn (show (stream "caaca" "*a"))
          putStrLn ("stream abacaaa a*a")
          putStrLn (show (stream "abacaaa" "a*a"))
          putStrLn ("stream abacaaa *")
          putStrLn (show (stream "abacaaa" "*"))
          putStrLn ("stream a ab")
          putStrLn (show (stream "a" "ab"))
          
