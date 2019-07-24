module Mod_firstChild ( firstChild ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types


trace' :: String -> a -> a
--trace' str x = (trace str x) 
trace' str x = x

data Data_firstChild  = Data_firstChild  {
  t :: Tree,
  n :: Node,
  res :: Node
}

--SIGNATURES
firstChild :: Tree -> Node -> Node
o_init :: Data_firstChild -> Node


--DEFINITIONS
firstChild t n = (o_init (Data_firstChild t n undefined))



o_init (Data_firstChild t n res) = (trace' "o_init" flow)
  where
    res' = (first (children t n))
    t' = t
    n' = n
    data' = (Data_firstChild t' n' res')
    flow =
      res'
