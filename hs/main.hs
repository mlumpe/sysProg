import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme

import Mod_treeToString
--import Mod_tokenize

--Code zum Testen der geschriebenen Funktionen


main = do putStrLn ("*** Tests Tokenize ***")
          putStrLn ("tokenize((((! a1) && 1 )-> (xyz || z)))")
          putStrLn (show (tokenize "(((! a1) && 1 )-> (xyz || z))" ))
          putStrLn ("tokenize(((abc && 0) -> x))")
          putStrLn (show ( tokenize "((abc && 0) -> x)" ))
          putStrLn ("")
          {-putStrLn ("*** Tests Parse & Eval & Satisfiable ***")
          putStrLn ("((abc && 0) -> x)")
          res = parse (tokenize ("((abc && 0) -> x)") )
          putStrLn (treeToString (get21 (res)))
          putStrLn (get22 (res))
          putStrLn ("Eval Tree & Map")
          --putStrLn (treeToString (get21 (eval (res))))    --eval
          --putStrLn (get22 (eval (res)))                   --eval
          --putStrLn ("Satisfiable: " ++ satisfiable (res)) --satisfiable
          putStrLn ("")-}
