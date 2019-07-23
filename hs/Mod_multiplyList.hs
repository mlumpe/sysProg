module Mod_multiplyList ( multiplyList ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

multiplyList :: [a] -> Int -> [a]
multiplyList list n = mLH list n 0 0 []

mLH :: [a] -> Int -> Int -> Int -> [a] -> [a]
mLH list n i j res | i == length list = res
                   | j == n = mLH list n (i+1) 0 res
				   | otherwise = mLH list n i (j+1) (append res (get list i))