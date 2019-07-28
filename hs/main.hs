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
input = "(((! 1) && 1 )-> (xyz || z))"
--input = "(((!a1) && 1 )-> (xyz || z))"
--input = "(((((!x1) || x2) || x3) && ((x2 || (!x3)) || x4)) && (x1 || (!x2)))"
--input = "((a || (!a)) -> (a2 && (!a2)))" -- false
--input = "((a || (!a)) -> ((a2 && (!a2)) || (a3 && a3)))" --true
--input = "((a || (!a)) -> ((a2 && (!a2)) || (a3 && (!a3))))" --false
--input = "(!(!(!(!(!1)))))" -- false

tokens = tokenize input
parsed = parse tokens
evaled = eval parsed
satisfiabled = satisfiable parsed
res = parse (tokenize (input) )

main = do putStrLn ("*** Tests Tokenize ***")
          putStrLn ("tokenize((((! a1) && 1 )-> (xyz || z)))")
          putStrLn (show (tokenize "(((! a1) && 1 )-> (xyz || z))" ))
          putStrLn ("tokenize(((abc && 0) -> x))")
          putStrLn (show (tokenize "((abc && 0) -> x)" ))
          putStrLn ("")
          putStrLn ("*** Tests Parse & Eval & Satisfiable ***")
          putStrLn (show (input))
          putStrLn (treeToString (get21 (res)))
          putStrLn (show (get22 (res)))
          putStrLn ("Eval Tree & Map")
          putStrLn (treeToString (get21 (eval (res))))
          putStrLn (show (get22 (eval (res))))
          putStrLn ("Satisfiable: " ++ show (satisfiable (res))) --satisfiable
          putStrLn ("")
