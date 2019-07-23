module Mod_fizzBuzz ( fizzBuzz ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types


--Signaturen
fizzBuzz    :: Int -> String
fizzBuzz_h1 :: Int -> String 
fizzBuzz_h2 :: String -> Bool
fizzBuzz_h3 :: String -> String -> String

--Definitionen
fizzBuzz n = 
    (reduce 
        fizzBuzz_h3 
        (filter 
            fizzBuzz_h2 
            (map 
                fizzBuzz_h1
                (firstNNumbers n))))

fizzBuzz_h1 i = 
    (sp_if 
        (sp_eq (sp_mod i 3) 0)
        (sp_if 
            (sp_eq (sp_mod i 5) 0)
            (join (show i) " : 15")
            (join (show i) " : 3")
        )
        (sp_if 
            (sp_eq (sp_mod i 5) 0)
            (join (show i) " : 5")
            ""
        )
    ) 

fizzBuzz_h2 x = (sp_neq x "")

fizzBuzz_h3 x y = (join (join x "\n") y)