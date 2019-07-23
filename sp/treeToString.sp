#NAME 
treeToString

#VARS 
tree    : Tree : i //i = Input-Variable
toVisit : ListNode
toVisitd: ListInt
act     : Node
d       : Int
res     : String : o //o = Output-Variable 

#CPP


#HS

#PREDS
leaf = (isLeaf tree act)
last = (empty toVisit)

#OPS
o_init: 
  act = (root tree)
  d = 0
  
o_out:
  res = (lc2s (join (s2lc res) (join (multiplyList [' '] (* d 3)) (s2lc (show act)))))
  
o_addChilds:
  toVisit = (join (children tree act) toVisit)
  toVisitd = (join (multiplyList [(+ d 1)] (length (children tree act))) toVisitd)
  
o_next:
  toVisit = (removeFirst toVisit)
  toVisitd = (removeFirst toVisitd)
  d = (first toVisitd)
  act = (first toVisit)

o_end:

 
#FLOW
o_init = o_out
o_out = (leaf (last o_end o_next) o_addChilds)
o_addChilds = o_next
o_next = o_out
o_end = RETURN





