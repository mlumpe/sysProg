{-module Mod_absolute ( absolute ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types

absolute :: Int -> Int
absolute x  | x < 0 = -x
            | x >= 0 = x-}


module Mod_absolute ( absolute ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types


trace' :: String -> a -> a
--trace' str x = (trace str x)
trace' str x = x

data Data_absolute  = Data_absolute  {
  a :: Int,
  res :: Int
}

--SIGNATURES
absolute :: Int -> Int
o_init :: Data_absolute -> Int


--DEFINITIONS
absolute a = (o_init (Data_absolute a undefined))



o_init (Data_absolute a res) = (trace' "o_init" flow)
  where
    res' = (sp_if (sp_lt a 0) (sp_minus 0 a) a)
    a' = a
    data' = (Data_absolute a' res')
    flow =
      res'
