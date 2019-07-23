module Mod_csmAlg ( csmAlg ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types

csmAlg :: CSMInstance -> Bool
csmAlg x | coa x == 0 && cob x == 0 = True
         | coa x == 0 || cob x == 0 = False
		 | otherwise = csmAlgHelper x 0 0 0 0

csmAlgHelper :: CSMInstance -> Int -> Int -> Int -> Int -> Bool
csmAlgHelper x ia ib acta actb | ia == coa x && ib == cob x = True
                             | sp_not (ssc x ia ib acta actb minl) = False
                             | ia < coa x && ib < cob x = nextStep x ia ib (acta+minl) (actb+minl)
                             | ia < coa x || ia < cob x = False
                              where 
                                 la = lena x (sp_min ia ((coa x)-1))
                                 lb = lenb x (sp_min ib ((cob x)-1))
                                 minl = sp_min (la-acta) (lb-actb)

nextStep :: CSMInstance -> Int -> Int -> Int -> Int -> Bool
nextStep x ia ib acta actb | acta == la && actb == lb = csmAlgHelper x (ia+1) (ib+1) 0 0
                         | acta == la = csmAlgHelper x (ia+1) ib 0 actb
						 | actb == lb = csmAlgHelper x ia (ib+1) acta 0
						  where
                             la = lena x ia
                             lb = lenb x ib