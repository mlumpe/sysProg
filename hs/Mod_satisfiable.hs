module Mod_satisfiable ( satisfiable ) where
import Prelude hiding (and, or)
import Debug.Trace
import Splib
import Types
import Mod_eval

isVariable s 
 | first s >= 'a' && first s <= 'z' = True
 | otherwise = False

getVariablesPos mapParam domain i res
 | i == length domain = res
 | isVariable (imageOf mapParam n) = getVariablesPos mapParam domain (i+1) res++[n]
 | otherwise = getVariablesPos mapParam domain (i+1) res
 where 
  n = get domain i

satisfiable ast
 | empty variables && imageOf resMap (root resTree) == "TRUE" = True
 | empty variables = False
 | otherwise = b1 || b2
 where
  evaled = eval ast
  resTree = get21 evaled
  resMap = get22 evaled
  map1 = setImage mapParam (first variables) "TRUE"
  map2 = setImage mapParam (first variables) "FALSE"
  b1 = satisfiable (set22 ast map1)
  b2 = satisfiable (set22 ast map2)
  variables = getVariablesPos mapParam (domainOf mapParam) 0 []
  mapParam = get22 ast