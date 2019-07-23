#NAME
absolute

#VARS
a    : Int : i
res : Int : o

#OPS
o_init:
    res = (sp_if (sp_lt a 0) (sp_minus 0 a) a)

#FLOW
o_init = RETURN
