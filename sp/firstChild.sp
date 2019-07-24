#Name
firstChild

#VARS
t	: Tree	: i
n	: Node	: i
res	: Node	: o

#OPS
o_init:
	res = (first (children t n)) 

#FLOW
o_init = RETURN
