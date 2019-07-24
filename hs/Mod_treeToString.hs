module Mod_treeToString ( treeToString ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types
import Mod_subtree

treeToString :: Tree -> String
treeToString tree = tTSHelper tree 0

tTSHelper :: Tree -> Int -> String
tTSHelper tree d = (tTSHelperSpaces 0 (3*d) []) ++ (show (root tree)) ++ "\n" ++ (tTSHelperChildren 0 tree [] d)

tTSHelperSpaces :: Int -> Int -> String -> String
tTSHelperSpaces i d res | i==d = res
                        | otherwise = tTSHelperSpaces (i+1) d (res ++ [' '])

tTSHelperChildren :: Int -> Tree -> String -> Int -> String
tTSHelperChildren i tree res d | i==length (children tree act) = res
                               | otherwise = tTSHelperChildren (i+1) tree (res ++ tTSHelper (subtree tree (get (children tree act) i)) (d+1)) d
                                where act = root tree
