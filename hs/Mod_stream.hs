module Mod_stream ( stream ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

stream :: String -> String -> [Int]
stream str pattern | length str < length pattern = []
                   | otherwise = trace "status;string;pattern;window" (streamHelper str pattern 0 [] [])
  
streamHelper :: String -> String -> Int -> String -> [Int] -> [Int]
streamHelper str pattern k window res 
 | k<length pattern = trace ("Aufbau;" ++ (lc2s str) ++ ";" ++ (lc2s pattern) ++ ";" ++ (lc2s window)) (streamHelper (removeFirst str) pattern (k+1) (append window (first str)) [])
 | empty str && equals window pattern = trace ("Ende+Match;" ++ (lc2s str) ++ ";" ++ (lc2s pattern) ++ ";" ++ (lc2s window)) (res ++ [k-(length pattern)])
 | empty str = trace ("Ende;" ++ (lc2s str) ++ ";" ++ (lc2s pattern) ++ ";" ++ (lc2s window) ) res
 | equals window pattern = trace ("Match;" ++ (lc2s str) ++ ";" ++ (lc2s pattern) ++ ";" ++ (lc2s window)) (streamHelper (removeFirst str) pattern (k+1) (shiftChar window (first str)) (res ++ [k-(length pattern)]))
 | otherwise = trace ("Kein Match;" ++ (lc2s str) ++ ";" ++ (lc2s pattern) ++ ";" ++ (lc2s window)) (streamHelper (removeFirst str) pattern (k+1) (shiftChar window (first str)) res)

equals window pattern 
 | empty window = True
 | first window == first pattern || first pattern == '*' = equals (removeFirst window) (removeFirst pattern)
 | otherwise = False

shiftChar :: String -> Char -> String
shiftChar str char = append (removeFirst str) char