#NAME 
subtree

#VARS 
tree    : Tree : i //i = Input-Variable
node    : Node : i 
res     : Tree : o //o = Output-Variable (kann nur eine geben)

#CPP


#HS

#PREDS

#OPS
o_init: 
  res = (newTreeOwn tree node)

 
#FLOW
o_init = RETURN




