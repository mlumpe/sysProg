#Name
firstChild

#VARS
t	: Tree	: i
n	: Node	: i
res	: Node	: o

#OPS
o_init:
	res = (first (children t i)) 

#FLOW
o_init = RETURN
