#NAME 
foliate 

#VARS 
inp     : ListInt : i //i = Input-Variable
cur     : Int  
lastMax : Int 
res     : List2Int : o //o = Output-Variable (kann nur eine geben)

#CPP
function<Int(Int)> foliate_h(Int k) {
    return [k](Int i) { return k + i; };
}

#HS
foliate_h k i = (k + i)

#PREDS
p_empty = (empty inp) 

#OPS
o_init: 
  res = []
  lastMax = 0

o_next:
  cur = (first inp)
  inp = (removeFirst inp)
  
  //mit cur' wird der neue Wert von cur (also "(first inp)") referenziert 
  res = (append res (map<Int,Int> (foliate_h lastMax) (firstNNumbers cur')))
  lastMax = (reduce<Int> sp_max (last res'))
  
  //Hinweis: falls var' benutzt wird, dann muss die Zuweisung von var
  //         bereits davor geschehen. In diesem Beispiel heißt das,
  //         dass "cur = ..." vor "res = ..." kommen muss und 
  //         "res = ..." vor "lastMax = ...", da lastMax res' verwendet 

o_end:
 
#FLOW
o_init = (p_empty o_end o_next)
o_next = (p_empty o_end o_next)
o_end = RETURN 

