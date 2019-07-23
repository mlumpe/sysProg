#NAME 
csmAlg

#HS
import Mod_csmEqLen

#CPP
#include "Mod_csmEqLen.cpp"

#VARS 
x  : CSMInstance : i
ca : Int 
cb : Int
oa : Int
ob : Int
l  : Int
r  : Bool : o

#PREDS
p_eqlen = (csmEqLen x)
p_ss    = ?
p_aleq  = ?
p_fc    = ?
p_eob   = ?
p_empty = ?

#OPS
o_init:  
  ?

o_alen:
  ?

o_blen:
  ?
    
o_anbs: 
  ?

o_asbn: 
  ?
    
o_anbn: 
  ?

o_noop:
  ?
  
o_yes:
  ?

o_no:
  ?

#FLOW
o_init = ?
o_alen = ?
o_blen = ?
o_anbs = ?
o_asbn = ?
o_anbn = ?
o_noop = ?
o_yes  = ?
o_no   = ?
