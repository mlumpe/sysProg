module Mod_addKAry ( addKAry ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types


trace' :: String -> a -> a
trace' str x = (trace str x) 
--trace' str x = x

data Data_addKAry  = Data_addKAry  { 
  base :: Int,
  list1 :: ListInt,
  list2 :: ListInt,
  carry :: Int,
  sum :: Int,
  res :: ListInt 
}

--SIGNATURES
addKAry :: Int -> ListInt -> ListInt -> ListInt
o_init :: Data_addKAry -> ListInt
o_next :: Data_addKAry -> ListInt
o_l1add :: Data_addKAry -> ListInt
o_l2add :: Data_addKAry -> ListInt
o_carry :: Data_addKAry -> ListInt
o_end :: Data_addKAry -> ListInt
o_calc :: Data_addKAry -> ListInt
o_calc_both :: Data_addKAry -> ListInt
o_calc_l1 :: Data_addKAry -> ListInt
o_calc_l2 :: Data_addKAry -> ListInt
l1_empty :: Data_addKAry -> Bool
l2_empty :: Data_addKAry -> Bool
or_empty :: Data_addKAry -> Bool
and_empty :: Data_addKAry -> Bool
carry_set :: Data_addKAry -> Bool

--DEFINITIONS
addKAry base list1 list2 = (o_init (Data_addKAry base list1 list2 undefined undefined undefined))

l1_empty (Data_addKAry base list1 list2 carry sum res) = 
  (empty list1)
l2_empty (Data_addKAry base list1 list2 carry sum res) = 
  (empty list2)
or_empty (Data_addKAry base list1 list2 carry sum res) = 
  (sp_or (empty list1) (empty list2))
and_empty (Data_addKAry base list1 list2 carry sum res) = 
  (sp_and (empty list1) (empty list2))
carry_set (Data_addKAry base list1 list2 carry sum res) = 
  (sp_eq carry 1)

o_init (Data_addKAry base list1 list2 carry sum res) = (trace' "o_init" flow)
  where
    res' = []
    carry' = 0
    base' = base
    list1' = list1
    list2' = list2
    sum' = sum
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (if' (and_empty data')
        (o_end data')
        (o_calc data')
      )

o_next (Data_addKAry base list1 list2 carry sum res) = (trace' "o_next" flow)
  where
    carry' = (sp_div sum base)
    res' = (prepend res (sp_mod sum base))
    list1' = (removeLast list1)
    list2' = (removeLast list2)
    base' = base
    sum' = sum
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (o_calc data')

o_l1add (Data_addKAry base list1 list2 carry sum res) = (trace' "o_l1add" flow)
  where
    carry' = (sp_div sum base)
    res' = (prepend res (sp_mod sum base))
    list1' = (removeLast list1)
    base' = base
    list2' = list2
    sum' = sum
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (if' (l1_empty data')
        (o_carry data')
        (o_calc data')
      )

o_l2add (Data_addKAry base list1 list2 carry sum res) = (trace' "o_l2add" flow)
  where
    carry' = (sp_div sum base)
    res' = (prepend res (sp_mod sum base))
    list2' = (removeLast list2)
    base' = base
    list1' = list1
    sum' = sum
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (if' (l2_empty data')
        (o_carry data')
        (o_calc data')
      )

o_carry (Data_addKAry base list1 list2 carry sum res) = (trace' "o_carry" flow)
  where
    res' = (sp_if (sp_eq carry 1) (prepend res carry) res)
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    sum' = sum
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (o_end data')

o_end (Data_addKAry base list1 list2 carry sum res) = (trace' "o_end" flow)
  where
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    sum' = sum
    res' = res
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      res'

o_calc (Data_addKAry base list1 list2 carry sum res) = (trace' "o_calc" flow)
  where
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    sum' = sum
    res' = res
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (if' (and_empty data')
        (o_carry data')
        (if' (or_empty data')
          (if' (l1_empty data')
            (o_calc_l2 data')
            (o_calc_l1 data')
          )
          (o_calc_both data')
        )
      )

o_calc_both (Data_addKAry base list1 list2 carry sum res) = (trace' "o_calc_both" flow)
  where
    sum' = (sp_add (last list1) (sp_add (last list2) carry))
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    res' = res
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (o_next data')

o_calc_l1 (Data_addKAry base list1 list2 carry sum res) = (trace' "o_calc_l1" flow)
  where
    sum' = (sp_add (last list1) carry)
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    res' = res
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (o_l1add data')

o_calc_l2 (Data_addKAry base list1 list2 carry sum res) = (trace' "o_calc_l2" flow)
  where
    sum' = (sp_add (last list2) carry)
    base' = base
    list1' = list1
    list2' = list2
    carry' = carry
    res' = res
    data' = (Data_addKAry base' list1' list2' carry' sum' res')
    flow = 
      (o_l2add data')
