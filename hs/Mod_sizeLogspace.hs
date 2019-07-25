module Mod_sizeLogspace ( sizeLogspace ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types
import Mod_firstChild
import Mod_hasNextSibling
import Mod_nextSibling

trace' :: String -> a -> a
--trace' str x = (trace str x) 
trace' str x = x

sizeLogspace tree node 
 | isLeaf tree node = 1
 | otherwise = trace' ("action;node;count\ndown;" ++ (show node) ++ ";" ++ (show 1)) (sizeHelper tree (firstChild tree node) 0 2 node)

sizeHelper t n lastA cnt start
 | n == start = cnt
 | downOrOver && (sp_not (isLeaf t n)) = trace' ("down;" ++ (show n) ++ ";" ++ show(cnt)) (sizeHelper t (firstChild t n) 0 (cnt+1) start)
 | downOrOver && hasNextSibling t n = trace' ("over;" ++ (show n) ++ ";" ++ show(cnt)) (sizeHelper t (nextSibling t n) 1 (cnt+1) start)
 | downOrOver = trace' ("up;" ++ (show n) ++ ";" ++ show(cnt)) (sizeHelper t (parent t n) 2 cnt start)
 | hasNextSibling t n = trace' ("over;" ++ (show n) ++ ";" ++ show(cnt)) (sizeHelper t (nextSibling t n) 1 (cnt+1) start)
 | otherwise = trace' ("up;" ++ (show n) ++ ";" ++ show(cnt)) (sizeHelper t (parent t n) 2 cnt start)
    where
     downOrOver = lastA == 0 || lastA == 1