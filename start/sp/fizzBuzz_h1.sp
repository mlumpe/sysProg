#NAME 
fizzBuzz_h1 

#VARS 
i   : Int : i     
res : String : o  

#PREDS
p_divisibleBy3 = (sp_eq (sp_mod i 3) 0)
p_divisibleBy5 = (== (% i 3) 0) //Schreibweise mit Operatoren

#OPS
o_init: //keine Variable wird verändert (noop)

o_both:
  res = (join (show i) " : 15")

o_only3:
  res = (join (show i) " : 3")

o_only5:
  res = (join (show i) " : 5")

o_none:
  res = ""
 
#FLOW
o_init = (p_divisibleBy3 (p_divisibleBy5 o_both o_only3) (p_divisibleBy5 o_only5 o_none))

o_both  = RETURN
o_only3 = RETURN
o_only5 = RETURN
o_none  = RETURN
