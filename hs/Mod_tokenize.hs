module Mod_tokenize ( tokenize ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

allowed = ['0'..'9'] ++ ['a'..'z']

tokenize :: String -> [(String, String)]
tokenize formel = tokenize_loop formel 0 []

tokenize_loop :: String -> Int -> [(String, String)] -> [(String, String)]
tokenize_loop formel i res
 | i == length formel = res 
 | next == '(' = tokenize_loop formel (i+1) (res++[("PO", "(")])
 | next == ')' = tokenize_loop formel (i+1) (res++[("PC", ")")])
 | next == '0' = tokenize_loop formel (i+1) (res++[("FALSE", "0")])
 | next == '1' = tokenize_loop formel (i+1) (res++[("TRUE", "1")])
 | next == '!' = tokenize_loop formel (i+1) (res++[("NOT", "!")])
 | next == '&' = tokenize_loop formel (i+2) (res++[("AND", "&&")])
 | next == '|' = tokenize_loop formel (i+2) (res++[("OR", "||")])
 | next == '-' = tokenize_loop formel (i+2) (res++[("IMPLY", "->")])
 | next == ' ' = tokenize_loop formel (i+1) res
 | otherwise = (tokenize_loop formel (offset) (res++[("VAR", var)]))
  where 
    offset = get21 (parseVar formel i [])
    var = get22 (parseVar formel i [])
    next = get formel i

parseVar :: String -> Int -> String -> (Int, String)
parseVar formel i res 
 | contains allowed next = parseVar formel (i+1) (res++[next])
 | otherwise = ((i), res)
  where
   next = get formel i