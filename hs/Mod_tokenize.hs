module Mod_tokenize ( tokenize ) where
import Prelude hiding (and, or)
import Splib
import Types

allowed = ['0'..'9'] ++ ['a'..'z']

tokenize :: String -> [(String, String)]
tokenize formel =

tokenize_loop formel i = | i == length formel = 0 
