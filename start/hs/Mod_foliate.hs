module Mod_foliate ( foliate ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

foliate_h k i = (k + i)

trace' :: String -> a -> a
trace' str x = (trace str x) 
trace' str x = x

data Data_foliate  = Data_foliate  {
  inp :: ListInt,
  cur :: Int,
  lastMax :: Int,
  res :: List2Int
}

--SIGNATURES
foliate :: ListInt -> List2Int
o_init :: Data_foliate -> List2Int
o_next :: Data_foliate -> List2Int
o_end :: Data_foliate -> List2Int
p_empty :: Data_foliate -> Bool

--DEFINITIONS
foliate inp = (o_init (Data_foliate inp undefined undefined undefined))

p_empty (Data_foliate inp cur lastMax res) =
  (empty inp)

o_init (Data_foliate inp cur lastMax res) = (trace' "o_init" flow)
  where
    res' = []
    lastMax' = 0
    inp' = inp
    cur' = cur
    data' = (Data_foliate inp' cur' lastMax' res')
    flow =
      (if' (p_empty data')
        (o_end data')
        (o_next data')
      )

o_next (Data_foliate inp cur lastMax res) = (trace' "o_next" flow)
  where
    cur' = (first inp)
    inp' = (removeFirst inp)
    res' = (append res (map (foliate_h lastMax) (firstNNumbers cur')))
    lastMax' = (reduce sp_max (last res'))
    data' = (Data_foliate inp' cur' lastMax' res')
    flow =
      (if' (p_empty data')
        (o_end data')
        (o_next data')
      )

o_end (Data_foliate inp cur lastMax res) = (trace' "o_end" flow)
  where
    inp' = inp
    cur' = cur
    lastMax' = lastMax
    res' = res
    data' = (Data_foliate inp' cur' lastMax' res')
    flow =
      res'
