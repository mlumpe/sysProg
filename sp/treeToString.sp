#NAME 
treeToString

#VARS 
tree    : Tree : i //i = Input-Variable
toVisit : ListNode
act     : Node
index   : Int
d       : Int
res     : String : o //o = Output-Variable 

#CPP


#HS

#PREDS
leaf = (isLeaf act)
last = (empty toVisit)

#OPS
o_init: 
  act = (root tree)
  d = 0
  toVisit = (children tree (root tree))
  
o_out:
  res = (append res act)
  
o_down:
  act = (first (children tree act))
  toVisit = (join (children tree act) toVisit)
  
o_next:
  toVisit = (removeFirst toVisit)
  act = (get toVisit 1)
  

 
#FLOW
o_init = o_out
o_out = (leaf o_next o_down)
o_down = o_out
o_next = (last o_end o_out)
o_end = RETURN





