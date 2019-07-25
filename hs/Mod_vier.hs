module Mod_vier ( vier ) where
import Prelude hiding (and, or) 
import Splib
import Debug.Trace
import Types
import Mod_absolute


trace' :: String -> a -> a
--trace' str x = (trace str x) 
trace' str x = x

dirChangeX :: Int -> Int -> Int
dirChangeX x a | a==0 || a==4 = x
               | a==1 || a==2 || a==3 = x+1
               | a==5 || a==6 || a==7 = x-1
               | otherwise = x
 
dirChangeY :: Int -> Int -> Int
dirChangeY y a | a==2 || a==6 = y
               | a==7 || a==0 || a==1 = y+1
               | a==3 || a==4 || a==5 = y-1
               | otherwise = y

checkBoundary :: [Int] -> Int -> Int -> Int -> Bool
checkBoundary matrix width x y | x>=0 && x<width && y>=0 && length matrix > (y*width+x) = True
                               | otherwise = False

bedingung :: [Int] -> Int -> Int -> Int -> Int -> Bool
bedingung matrix width x y player 
 | sp_not (checkBoundary matrix width x y) = False
 | get matrix pos /= player = False
 | otherwise = True
     where
      pos = y*width+x
 
checkWon :: [Int] -> Int -> Int -> Int ->Int -> Int -> Int -> Int -> Int -> [Int] -> Int -> Bool
checkWon matrix width x y xStart yStart player a i steine cnt
 | a == 8 = checkWonList steine
 | i == 4 = checkWon matrix width xStart yStart xStart yStart player (a+1) 0 (steine ++ [cnt]) 0
 | bedingung matrix width x y player = checkWon matrix width (dirChangeX x a) (dirChangeY y a) xStart yStart player a (i+1) steine (cnt+1)
 | otherwise = checkWon matrix width xStart yStart xStart yStart player (a+1) 0 (steine ++ [cnt]) 0
 
checkWonList :: [Int] -> Bool
checkWonList steine
 | (get steine 0)+(get steine 4) > 4 = True
 | (get steine 1)+(get steine 5) > 4 = True
 | (get steine 2)+(get steine 6) > 4 = True
 | (get steine 3)+(get steine 7) > 4 = True
 | otherwise = False
 
calcMax :: [Int] -> Int -> Int -> Int
calcMax zugfolge i maxV 
 | i == length zugfolge = maxV
 | otherwise = calcMax zugfolge (i+1) (sp_max maxV (absolute (get zugfolge i)))
 
vier :: [Int] -> Int
vier zugfolge = vierHelper zugfolge [] 0

vierHelper :: [Int] -> [Int] -> Int -> Int
vierHelper zugfolge matrix i
 | i== length zugfolge = 0
 | checkWon matrixNeu width x y x y player 0 0 [] 0 = player
 | otherwise = vierHelper zugfolge matrixNeu (i+1)
          where 
           player = (sp_mod i 2)+1
           other | player == 1 = 2
                 | otherwise = 1
           x = (get zugfolge i) + maxV
           maxV = calcMax zugfolge 0 0
           width = 2*maxV+1
           matrixNeu = get21 (calcMatrix matrix width x 0 player)
           y = get22 (calcMatrix matrix width x 0 player)

calcMatrix :: [Int] -> Int -> Int -> Int -> Int -> ([Int],Int)
calcMatrix matrix width x h player 
 | length matrix <= pos = calcMatrix (append matrix 0) width x h player
 | get matrix pos == 0 = tuple2 (set matrix pos player) h
 | otherwise = calcMatrix matrix width x (h+1) player
        where 
         pos = h*width +x
  

