import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_tokenize
import Mod_parse
import Mod_eval
import Mod_satisfiable
import Mod_treeToString

--Code zum Testen der geschriebenen Funktionen
input = "(((! a1) && 1 )-> (xyz || z))"
tokens = tokenize input
parsed = parse tokens
evaled = eval parsed
satisfiabled = satisfiable parsed

main = do putStrLn ("*** Tests ***")
          putStrLn ("tokenize((((! a1) && 1 )-> (xyz || z))")
          putStrLn (show tokens)
          putStrLn (treeToString (get21 parsed))
          putStrLn (show (get22 parsed))
          putStrLn (treeToString (get21 evaled))
          putStrLn (show (get22 evaled))
          putStrLn (show satisfiabled)
