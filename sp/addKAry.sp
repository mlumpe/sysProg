#NAME 
addKAry

#VARS 
base    : Int : i //i = Input-Variable
list1   : ListInt : i 
list2   : ListInt : i
carry   : Int
sum     : Int
res     : ListInt : o //o = Output-Variable (kann nur eine geben)

#CPP


#HS

#PREDS
l1_empty = (empty list1) 
l2_empty = (empty list2)
or_empty = (sp_or (empty list1)  (empty list2))
and_empty = (sp_and (empty list1)  (empty list2))
carry_set = (sp_eq carry 1)

#OPS
o_init: 
  res = []
  carry = 0

o_next:
  carry = (sp_div sum base)
  
  res = (prepend res (sp_mod sum base))
  list1 = (removeLast list1)
  list2 = (removeLast list2)
  
o_l1add:
  carry = (sp_div sum base)
  sum = (sp_mod sum base)
  
  res = (prepend res sum)
  list1 = (removeLast list1)
  
o_l2add:
  carry = (sp_div sum base)
  sum = (sp_mod sum base)
  
  res = (prepend res sum)
  list2 = (removeLast list2)
  
o_carry:
  res = (prepend res 1)
  
o_end:

o_calc:

o_calc_both:
  sum = (sp_add (last list1) (sp_add (last list2) carry))
  
o_calc_l1:
  sum = (sp_add (last list1) carry)
  
o_calc_l2:
  sum = (sp_add (last list2) carry)
 
#FLOW
o_init = (and_empty o_end o_calc)
o_next = (o_calc)
o_l2add = (l2_empty (carry_set o_carry o_end) o_calc)
o_l1add = (l1_empty (carry_set o_carry o_end) o_calc)
o_carry = (o_end)
o_calc = (or_empty (l1_empty o_calc_l2 o_calc_l1) o_calc_both)
o_calc_both = o_next
o_calc_l1 = o_l1add
o_calc_l2 = o_l2add
o_end = RETURN 



