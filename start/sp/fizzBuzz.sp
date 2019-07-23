#NAME 
fizzBuzz 

#CPP 
//nachfolgender Code steht nur in der C++-Übersetzung
/* Anfang: nur in C++ */

#include "Mod_fizzBuzz_h1.cpp"

Bool fizzBuzz_h2(String x) {
    return sp_neq<String>(x,"");
}

String fizzBuzz_h3(String x, String y) {
    return join(join(x,"\n"),y);
}

/* Ende: nur in C++ */

#HS
//nachfolgender Code steht nur in der Haskell-Übersetzung
--Anfang: nur in Haskell

import Mod_fizzBuzz_h1

fizzBuzz_h2 x = (sp_neq x "")
fizzBuzz_h3 x y = (join (join x "\n") y)

--Ende: nur in Haskell


#VARS 
n   : Int : i     //i = Input-Variable
res : String : o  //o = Output-Variable

#PREDS
//keine Prädikate benötigt

#OPS
o_init: 
  res = (reduce<String> fizzBuzz_h3 (filter<String> fizzBuzz_h2 (map<Int,String> fizzBuzz_h1 (firstNNumbers n))))  
 
#FLOW
o_init = RETURN