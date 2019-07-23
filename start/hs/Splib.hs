{-
  splib v1.0
  In dieser Datei sollte nichts verändert werden!
-}

module Splib where
import qualified Data.List

if' :: Bool -> a -> a -> a 
if' True x _ = x
if' False _ y = y
sp_if = if'

true = True
false = False


-- **** Operator aliases ****

sp_add a b = (a + b)
sp_minus a b = (a - b)
sp_mult a b = (a * b)
sp_pow a b = (a ^ b)
sp_div a b = (div a b)
sp_mod a b = (mod a b)
sp_max a b = (max a b)
sp_min a b = (min a b)

sp_eq a b = (a == b)
sp_neq a b = (a /= b)
sp_gt a b = (a > b)
sp_lt a b = (a < b)
sp_leq a b = (a <= b) 
sp_geq a b = (a >= b)

sp_and a b = (a && b) 
sp_or a b = (a || b)
sp_not a = (not a)


-- **** Misc functions ****
lc2s :: String -> String
s2lc :: String -> String
c2s :: Char -> String
s2s :: String -> String

-- Definitions
lc2s x = x    
s2lc x = x
c2s x = [x] 
s2s x = x 


-- **** Higher-order functions ****

--map      :: (a -> b) -> [a] -> [b] ; already defined in Prelude
reduce     :: (a -> a -> a) -> [a] -> a 
--filter   :: (a -> Bool) -> [a] -> [a] ; already defined in Prelude
firstMatch :: (a -> Bool) -> [a] -> a
firstMatchIndex :: (a -> Bool) -> [a] -> Int
combine    :: (a -> b -> c) -> [a] -> [b] -> [c] 

-- Definitions
reduce f list = 
    (if' ((length list) == 1)
        (first list)
        (reduce f 
            ( (f (first list) (get list 1)) 
             : (removeFirst (removeFirst list)))
        )    
    )

firstMatch pred list = (list!!(firstMatchIndex pred list))    
firstMatchIndex pred list = (find 0)
    where
        find index = 
            (if' (pred (list!!index))
                index
                (find (index+1))
            )
            
combine f [] [] = []
combine f (x:xs) (y:ys) = (f x y):(combine f xs ys)


-- **** List functions ****

get    :: [a] -> Int -> a 
first  :: [a] -> a 
--last :: [a] -> a ; already defined in Prelude

--length :: [a] -> Int ; already defined in Prelude
contains :: (Eq a) => [a] -> a -> Bool 
empty    :: [a] -> Bool

append       :: [a] -> a -> [a]
prepend      :: [a] -> a -> [a]
set          :: [a] -> Int -> a -> [a]
insert       :: [a] -> Int -> a -> [a]
remove       :: [a] -> Int -> [a]
removeFirst  :: [a] -> [a]
removeLast   :: [a] -> [a]
join         :: [a] -> [a] -> [a]
sublist      :: [a] -> Int -> Int -> [a]
--reverse    :: [a] -> [a] ; already defined in Prelude
--setCompare   :: [a] -> [a] -> Bool

-- Definitions
get list index = (list!!index)

first list = (list!!0)

contains list val = (elem val list)  

empty list = (null list)

append list val = (list++[val])

prepend list val = (val:list)

set list index val = 
    (if' (index == 0)
        (prepend (removeFirst list) val)
        (prepend (set (removeFirst list) (index - 1) val) (first list))
    )

insert list index val = 
    (if' (index == 0)
        (prepend list val)
        ((first list):(insert (removeFirst list) (index-1) val))
    )

remove list index = 
    (if' (index == 0) 
        (removeFirst list)
        ((first list):(remove (removeFirst list) (index -1)))
    )    

removeFirst list = (tail list)

removeLast list = (init list)

join list1 list2 = list1 ++ list2

--sublist lst start len = take len (drop start lst)
sublist _ _ 0 = []
sublist list start length = 
    (if' (start == 0)
        ((first list):(sublist (removeFirst list) 0 (length - 1)))
        (sublist (removeFirst list) (start - 1) length)
    )   

    
-- **** Tree data type ****

data Node = Node Int deriving (Eq,Ord)
data Tree = Tree Node [(Node,[Node])] --(rootNode,childrenList)

instance Show Node where 
    show (Node id) = (show id)
instance Show Tree where 
    show (Tree r l) = (show l) 
    
root     :: Tree -> Node
parent   :: Tree -> Node -> Node
lastNode :: Tree -> Node

children :: Tree -> Node -> [Node]

size :: Tree -> Int 

isRoot :: Tree -> Node -> Bool
isLeaf :: Tree -> Node -> Bool

newTree    :: Tree    
newTreeOwn :: Node -> Tree
addLeaf    :: Tree -> Node -> Tree
addOwnLeaf :: Tree -> Node -> Node -> Tree
removeLeaf :: Tree -> Node -> Tree

createNode :: Int -> Node

-- Definitions

createNode x = (Node x)

root (Tree r _) = r

parent (Tree _ list) v = ((\(x,y) -> x) uData)
    where
        select (_,uChildren) = (contains uChildren v) 
        uData = (firstMatch select list)

lastNode (Tree _ list) = ((\(x,y) -> x) (last list))     

children (Tree _ list) v = ((\(x,y) -> y) (firstMatch (tree_h_select v) list))     

size (Tree _ list) = (length list)

isRoot (Tree r _) v = (r == v)

isLeaf t v = (empty (children t v))    

newTreeOwn r = (Tree r [(r,[])])
newTree = (newTreeOwn (Node 1))

addOwnLeaf (Tree r list) v w = (Tree r (append (set list vDataIndex vDataNew) (w,[]) ))
    where                 
        vDataIndex = (firstMatchIndex (tree_h_select v) list)
        vDataNew = (v,(append (children (Tree r list) v) w)) 

addLeaf (Tree r list) v = (addOwnLeaf (Tree r list) v w)
    where 
        w = (Node ((reduce max (map (nodeId . (\(x,y) -> x)) list))+1)) --new node                       
        nodeId (Node x) = x

removeLeaf (Tree r list) v = (Tree r (remove list2 vIndex))
    where
        t = ((Tree r list))
        vIndex = (firstMatchIndex (tree_h_select v) list)        
        u = (parent t v)        
        uIndex = (firstMatchIndex (tree_h_select u) list)
        vuIndex = (firstMatchIndex (== v) (children t u))               
        list2 = (set list uIndex (u, (remove (children t u) vuIndex)))        
     
tree_h_select v (u,_) = (v == u)

instance Eq Tree where  
    (Tree r1 l1) == (Tree r2 l2) = ((r1 == r2) && ((Map l1') == (Map l2')))
      where
        l1' = (map f1 l1)
        l2' = (map f1 l2)
        f1 (x,y) = (x,(Data.List.sort y)) 
--l1 = [(x,y)] -> [(x,Data.List.sort(y))]

-- **** CSM data type ****

data CSMInstance = CSMInstance [String] [String] 

createCSM :: [String] -> [String] -> CSMInstance
coa  :: CSMInstance -> Int
cob  :: CSMInstance -> Int
lena :: CSMInstance -> Int -> Int
lenb :: CSMInstance -> Int -> Int
ssc :: CSMInstance -> Int -> Int -> Int -> Int -> Int -> Bool

-- Definitions
createCSM a b = (CSMInstance a b)
coa (CSMInstance a b) =  length a
cob (CSMInstance a b) =  length b
lena (CSMInstance a b) i = length (a!!i)
lenb (CSMInstance a b) i = length (b!!i)
ssc (CSMInstance a b) ca cb oa ob l = (sublist (a!!ca) oa l) == (sublist (b!!cb) ob l) 
            
                
instance Show CSMInstance where
    show (CSMInstance a b) = (show (a,b)) 
                
-- **** Map data type ****

data Map a b = Map [(a,b)] 

instance (Show a, Show b) => Show (Map a b) where
    show (Map x) = (show x) 

emptyMap  :: (Map a b)
isMap     :: (Eq a, Eq b) => (Map a b) -> Bool 
isDefined :: (Eq a, Eq b) => (Map a b) -> a -> Bool 
imageOf   :: (Eq a, Eq b) => (Map a b) -> a -> b
inverseOf :: (Eq a, Eq b) => (Map a b) -> b -> [a]
undefine  :: (Eq a, Eq b) => (Map a b) -> a -> (Map a b)
setImage  :: (Eq a, Eq b) => (Map a b) -> a -> b -> (Map a b)
domainOf  :: (Map a b) -> [a]
joinMaps  :: (Map a b) -> (Map a b) -> (Map a b) 

-- Definitions
emptyMap = (Map [])

isMap (Map m) = ((length (Data.List.nub m2)) == (length m2))
    where
        m2 = (map get21 m)
    
isDefined (Map m) x = (sp_not (empty m2))    
    where
        m2 = (filter (sp_eq x) (map get21 m))
        
imageOf (Map m) x = (get22 (first (filter pred m)))
    where 
        pred (a,b) = (sp_eq x a) 

inverseOf (Map m) y = (map get21 (filter pred m))
    where 
        pred (a,b) = (sp_eq y b) 

undefine (Map m) x = (Map (filter pred m))
    where 
        pred (a,b) = (not (sp_eq x a))

setImage (Map m) x y = (Map (append m1 (x,y)))
    where 
        m1 = (raw (undefine (Map m) x))
        raw (Map m) = m 
        
domainOf (Map m) = (map f m) 
    where 
        f (x,y) = x
        
joinMaps (Map m1) (Map m2) = (Map (join m1 m2))         
        
instance (Eq a, Eq b) => Eq (Map a b) where  
    (Map []) == (Map []) = True 
    (Map m1) == (Map m2) = (sp_and (sp_eq (length m1) (length m2)) (reduce sp_and (map f2 domf1)) ) 
        where
            domf1 = (map get21 m1)
            f2 x = ((isDefined (Map m2) x) && (sp_eq (imageOf (Map m1) x) (imageOf (Map m2) x)))

            
-- **** setCompare for Lists ****

data (Data_setCompare a) = Data_setCompare  { 
  l1 :: [a],
  l2 :: [a],
  r :: Bool,
  x :: a,
  i :: Int 
}

--SIGNATURES
setCompare :: (Eq a) => [a] -> [a] -> Bool
setCompare_o_init :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_next :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_find1 :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_find2 :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_remove :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_yes :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_o_no :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_p_diffSize :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_p_bothEmpty :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_p_contains :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_p_last :: (Eq a) => (Data_setCompare a) -> Bool
setCompare_p_match :: (Eq a) => (Data_setCompare a) -> Bool

--DEFINITIONS
setCompare l1 l2 = (setCompare_o_init (Data_setCompare l1 l2 undefined undefined undefined))

setCompare_p_diffSize (Data_setCompare l1 l2 r x i) = 
  ((length l1) /= (length l2))
setCompare_p_bothEmpty (Data_setCompare l1 l2 r x i) = 
  ((empty l1) && (empty l2))
setCompare_p_contains (Data_setCompare l1 l2 r x i) = 
  (contains l2 x)
setCompare_p_last (Data_setCompare l1 l2 r x i) = 
  ((length l1) == 0)
setCompare_p_match (Data_setCompare l1 l2 r x i) = 
  (x == (get l2 i))

setCompare_o_init (Data_setCompare l1 l2 r x i) = flow
  where
    l1' = l1
    l2' = l2
    r' = r
    x' = x
    i' = i
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      (if' (setCompare_p_diffSize data')
        (setCompare_o_no data')
        (if' (setCompare_p_bothEmpty data')
          (setCompare_o_yes data')
          (setCompare_o_next data')
        )
      )

setCompare_o_next (Data_setCompare l1 l2 r x i) = flow
  where
    x' = (first l1)
    l1' = (removeFirst l1)
    l2' = l2
    r' = r
    i' = i
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      (if' (setCompare_p_contains data')
        (if' (setCompare_p_last data')
          (setCompare_o_yes data')
          (setCompare_o_find1 data')
        )
        (setCompare_o_no data')
      )

setCompare_o_find1 (Data_setCompare l1 l2 r x i) = flow
  where
    i' = 0
    l1' = l1
    l2' = l2
    r' = r
    x' = x
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      (if' (setCompare_p_match data')
        (setCompare_o_remove data')
        (setCompare_o_find2 data')
      )

setCompare_o_find2 (Data_setCompare l1 l2 r x i) = flow
  where
    i' = (i + 1)
    l1' = l1
    l2' = l2
    r' = r
    x' = x
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      (if' (setCompare_p_match data')
        (setCompare_o_remove data')
        (setCompare_o_find2 data')
      )

setCompare_o_remove (Data_setCompare l1 l2 r x i) = flow
  where
    l2' = (remove l2 i)
    l1' = l1
    r' = r
    x' = x
    i' = i
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      (setCompare_o_next data')

setCompare_o_yes (Data_setCompare l1 l2 r x i) = flow
  where
    r' = true
    l1' = l1
    l2' = l2
    x' = x
    i' = i
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      r'

setCompare_o_no (Data_setCompare l1 l2 r x i) = flow
  where
    r' = false
    l1' = l1
    l2' = l2
    x' = x
    i' = i
    data' = (Data_setCompare l1' l2' r' x' i')
    flow = 
      r'
    
-- **** Tuples ****
tuple2 x1 x2 = (x1, x2)
get21 (x1, x2) = x1
get22 (x1, x2) = x2
set21 (x1, x2) x0 = (x0, x2)
set22 (x1, x2) x0 = (x1, x0)

tuple3 x1 x2 x3 = (x1, x2, x3)
get31 (x1, x2, x3) = x1
get32 (x1, x2, x3) = x2
get33 (x1, x2, x3) = x3
set31 (x1, x2, x3) x0 = (x0, x2, x3)
set32 (x1, x2, x3) x0 = (x1, x0, x3)
set33 (x1, x2, x3) x0 = (x1, x2, x0)

tuple4 x1 x2 x3 x4 = (x1, x2, x3, x4)
get41 (x1, x2, x3, x4) = x1
get42 (x1, x2, x3, x4) = x2
get43 (x1, x2, x3, x4) = x3
get44 (x1, x2, x3, x4) = x4
set41 (x1, x2, x3, x4) x0 = (x0, x2, x3, x4)
set42 (x1, x2, x3, x4) x0 = (x1, x0, x3, x4)
set43 (x1, x2, x3, x4) x0 = (x1, x2, x0, x4)
set44 (x1, x2, x3, x4) x0 = (x1, x2, x3, x0)

tuple5 x1 x2 x3 x4 x5 = (x1, x2, x3, x4, x5)
get51 (x1, x2, x3, x4, x5) = x1
get52 (x1, x2, x3, x4, x5) = x2
get53 (x1, x2, x3, x4, x5) = x3
get54 (x1, x2, x3, x4, x5) = x4
get55 (x1, x2, x3, x4, x5) = x5
set51 (x1, x2, x3, x4, x5) x0 = (x0, x2, x3, x4, x5)
set52 (x1, x2, x3, x4, x5) x0 = (x1, x0, x3, x4, x5)
set53 (x1, x2, x3, x4, x5) x0 = (x1, x2, x0, x4, x5)
set54 (x1, x2, x3, x4, x5) x0 = (x1, x2, x3, x0, x5)
set55 (x1, x2, x3, x4, x5) x0 = (x1, x2, x3, x4, x0)

tuple6 x1 x2 x3 x4 x5 x6 = (x1, x2, x3, x4, x5, x6)
get61 (x1, x2, x3, x4, x5, x6) = x1
get62 (x1, x2, x3, x4, x5, x6) = x2
get63 (x1, x2, x3, x4, x5, x6) = x3
get64 (x1, x2, x3, x4, x5, x6) = x4
get65 (x1, x2, x3, x4, x5, x6) = x5
get66 (x1, x2, x3, x4, x5, x6) = x6
set61 (x1, x2, x3, x4, x5, x6) x0 = (x0, x2, x3, x4, x5, x6)
set62 (x1, x2, x3, x4, x5, x6) x0 = (x1, x0, x3, x4, x5, x6)
set63 (x1, x2, x3, x4, x5, x6) x0 = (x1, x2, x0, x4, x5, x6)
set64 (x1, x2, x3, x4, x5, x6) x0 = (x1, x2, x3, x0, x5, x6)
set65 (x1, x2, x3, x4, x5, x6) x0 = (x1, x2, x3, x4, x0, x6)
set66 (x1, x2, x3, x4, x5, x6) x0 = (x1, x2, x3, x4, x5, x0)

tuple7 x1 x2 x3 x4 x5 x6 x7 = (x1, x2, x3, x4, x5, x6, x7)
get71 (x1, x2, x3, x4, x5, x6, x7) = x1
get72 (x1, x2, x3, x4, x5, x6, x7) = x2
get73 (x1, x2, x3, x4, x5, x6, x7) = x3
get74 (x1, x2, x3, x4, x5, x6, x7) = x4
get75 (x1, x2, x3, x4, x5, x6, x7) = x5
get76 (x1, x2, x3, x4, x5, x6, x7) = x6
get77 (x1, x2, x3, x4, x5, x6, x7) = x7
set71 (x1, x2, x3, x4, x5, x6, x7) x0 = (x0, x2, x3, x4, x5, x6, x7)
set72 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x0, x3, x4, x5, x6, x7)
set73 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x2, x0, x4, x5, x6, x7)
set74 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x2, x3, x0, x5, x6, x7)
set75 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x2, x3, x4, x0, x6, x7)
set76 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x2, x3, x4, x5, x0, x7)
set77 (x1, x2, x3, x4, x5, x6, x7) x0 = (x1, x2, x3, x4, x5, x6, x0)

tuple8 x1 x2 x3 x4 x5 x6 x7 x8 = (x1, x2, x3, x4, x5, x6, x7, x8)
get81 (x1, x2, x3, x4, x5, x6, x7, x8) = x1
get82 (x1, x2, x3, x4, x5, x6, x7, x8) = x2
get83 (x1, x2, x3, x4, x5, x6, x7, x8) = x3
get84 (x1, x2, x3, x4, x5, x6, x7, x8) = x4
get85 (x1, x2, x3, x4, x5, x6, x7, x8) = x5
get86 (x1, x2, x3, x4, x5, x6, x7, x8) = x6
get87 (x1, x2, x3, x4, x5, x6, x7, x8) = x7
get88 (x1, x2, x3, x4, x5, x6, x7, x8) = x8
set81 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x0, x2, x3, x4, x5, x6, x7, x8)
set82 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x0, x3, x4, x5, x6, x7, x8)
set83 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x0, x4, x5, x6, x7, x8)
set84 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x3, x0, x5, x6, x7, x8)
set85 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x3, x4, x0, x6, x7, x8)
set86 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x3, x4, x5, x0, x7, x8)
set87 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x3, x4, x5, x6, x0, x8)
set88 (x1, x2, x3, x4, x5, x6, x7, x8) x0 = (x1, x2, x3, x4, x5, x6, x7, x0)

tuple9 x1 x2 x3 x4 x5 x6 x7 x8 x9 = (x1, x2, x3, x4, x5, x6, x7, x8, x9)
get91 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x1
get92 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x2
get93 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x3
get94 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x4
get95 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x5
get96 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x6
get97 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x7
get98 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x8
get99 (x1, x2, x3, x4, x5, x6, x7, x8, x9) = x9
set91 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x0, x2, x3, x4, x5, x6, x7, x8, x9)
set92 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x0, x3, x4, x5, x6, x7, x8, x9)
set93 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x0, x4, x5, x6, x7, x8, x9)
set94 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x0, x5, x6, x7, x8, x9)
set95 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x4, x0, x6, x7, x8, x9)
set96 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x4, x5, x0, x7, x8, x9)
set97 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x4, x5, x6, x0, x8, x9)
set98 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x4, x5, x6, x7, x0, x9)
set99 (x1, x2, x3, x4, x5, x6, x7, x8, x9) x0 = (x1, x2, x3, x4, x5, x6, x7, x8, x0)