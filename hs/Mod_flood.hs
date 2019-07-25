module Mod_flood ( flood ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

flood :: String -> Int -> Int -> Int -> String
flood str width x y = floodHelper (floodHelper (floodHelper (floodHelper (set str pos color) width x (y+1) color) width x (y-1) color) width (x+1) y color) width (x-1) y color
                where 
                 pos = width*(y)+(x+1)-1
                 color | get str pos == 'b' = 'w'
                       | otherwise = 'b'

floodHelper :: String -> Int -> Int -> Int -> Char -> String
floodHelper str width x y newColor 
 | get str safePos == newColor = str
 | otherwise = flood str width x y
        where 
          pos = width*(y)+(x+1)-1
          safeX = sp_max (sp_min x (width-1)) 0
          safeY = sp_max (sp_min y ((sp_div (length str) width)-1)) 0
          safePos = width*safeY+safeX