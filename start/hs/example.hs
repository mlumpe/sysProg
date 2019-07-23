import Splib hiding (x,r,i,l1,l2)
import Types

{-
  Im Gegensatz zu C++ benötigen higher-order Funktionen
  in Haskell keine spezielle Syntax
-}

doSomething :: Int -> (Int -> String) -> String
doSomething x f = (f x)

squareAndAddA :: Int -> Int -> Int 
squareAndAddA a x = ((x * x) + a);
{-
  die Signatur von squareAndAddA ist 
  äquivalent zu Int -> (Int -> Int) 
  da -> rechtsassoziativ ist 
-}

biggerThanA :: Int -> Int -> Bool
biggerThanA a x = (sp_gt x a)

--Konstruieren der Datentypen aus der splib
v_int1, v_int2 :: Int
v_char :: Char
v_bool1, v_bool2 :: Bool
v_string1, v_string2 :: String 

v_int1 = 12
v_int2 = (-4)
v_char = 'x'
v_bool1 = true 
v_bool2 = false
v_string1 = "asd"
v_string2 = "test 1234!" 


--List
v_list1, v_list7, v_list8 :: [Int]
v_list2 :: [[Int]]
v_list3, v_list6 :: [Bool]
v_list4, v_list9 :: [Char]
v_list5 :: [String]

v_list1 = [3,(-2),14,5,6]
v_list2 = [[1,2],[3,4,5],[],[6]]
v_list3 = []
v_list4 = ['a','b','c']
v_list5 = ["str1","str2","str3"]
v_list6 = [true,false,true]
v_list7 = [3,(-2),14,5,6]
v_list8 = [0,1,2,3,4,5]
v_list9 = ['a','b','c','d','e','f']


--Map
{-
  Die Bezeichner (v_int1, v_char, ...) die wir bisher
  definiert haben sind keine Variablen sondern Funktionen
  ohne Eingabeparameter. Wie in C++ gilt auch in Haskell, dass
  eine Funktion nur einmal definiert werden kann. Deshalb
  müssen beim Aufbauen komplexerer Daten verschiedene Bezeichner 
  gewählt werden (v_map1_0, v_map1_1, ...). 
-}
v_map1, v_map3, v_map4, v_map5 :: (Map Int String)
v_map2 :: (Map Char Bool)

v_map1_0 = (emptyMap)
v_map1_1 = (setImage v_map1_0 1 "one")
v_map1_2 = (setImage v_map1_1 2 "two")
v_map1_3 = (setImage v_map1_2 3 "three")
v_map1 = v_map1_3

v_map2_0 = (emptyMap)
v_map2_1 = (setImage v_map2_0 'a' true)
v_map2_2 = (setImage v_map2_1 'b' false)    
v_map2_3 = (setImage v_map2_2 'c' true)
v_map2_4 = (setImage v_map2_3 'd' false)
v_map2_5 = (setImage v_map2_4 'e' true) 
v_map2 = v_map2_5

v_map3_0 = (emptyMap)
v_map3_1 = (setImage v_map3_0 3 "three")
v_map3_2 = (setImage v_map3_1 2 "two")  
v_map3_3 = (setImage v_map3_2 1 "one")         
v_map3 = v_map3_3
              
v_map4_0 = (emptyMap)
v_map4_1 = (setImage v_map4_0 3 "three")
v_map4_2 = (setImage v_map4_1 2 "two")  
v_map4_3 = (setImage v_map4_2 1 "not one")     
v_map4 = v_map4_3

v_map5 = (emptyMap)


--Tuple 
v_tuple1, v_tuple3, v_tuple4 :: (String,Int)
v_tuple2 :: (String,Int,Int,Bool)

v_tuple1 = ("tuple1",34)   
v_tuple2 = ("tuple2",(-3),4,true)       
v_tuple3 = ("tuple3",34)
v_tuple4 = ("tuple4",1)


--Tree & Node
v_tree1,v_tree2 :: Tree
v_tree1_n1, v_tree1_n2, v_tree1_n3 :: Node

v_tree1_0 = (newTree)  
v_tree1_n1 = (lastNode v_tree1_0) 
    
v_tree1_1 = (addLeaf v_tree1_0 v_tree1_n1) 
v_tree1_n2 = (lastNode v_tree1_1) 

v_tree1_2 = (addLeaf v_tree1_1 v_tree1_n1) 
v_tree1_n3 = (lastNode v_tree1_2)     

v_tree1_3 = (addLeaf v_tree1_2 v_tree1_n2) 
v_tree1_4 = (addLeaf v_tree1_3 v_tree1_n3) 
v_tree1_5 = (addLeaf v_tree1_4 v_tree1_n3) 

v_tree1 = v_tree1_5

v_tree2_0 = (newTreeOwn (createNode 1))
v_tree2_1 = (addOwnLeaf v_tree2_0 (createNode 1) (createNode 2))
v_tree2_2 = (addOwnLeaf v_tree2_1 (createNode 1) (createNode 5))
v_tree2_3 = (addOwnLeaf v_tree2_2 (createNode 2) (createNode 3))
v_tree2_4 = (addOwnLeaf v_tree2_3 (createNode 2) (createNode 4))
v_tree2_5 = (addOwnLeaf v_tree2_4 (createNode 5) (createNode 6))
v_tree2_6 = (addOwnLeaf v_tree2_5 (createNode 5) (createNode 7))
v_tree2 = v_tree2_6 

--CSMInstance
v_csm :: CSMInstance
v_csm = (createCSM ["cece","ce","ce","ce"] ["ce","cec","ece","ce"])

--Ausgabe der Ergebnisse
main = do     
    putStrLn ("v_int1: " ++ show(v_int1))
    putStrLn ("v_int2: " ++ show(v_int2))
    putStrLn ("v_char: " ++ show(v_char))
    putStrLn ("v_bool1: " ++ show(v_bool1))
    putStrLn ("v_bool2: " ++ show(v_bool2))
    putStrLn ("v_string1: " ++ show(v_string1))
    putStrLn ("v_string2: " ++ show(v_string2))
    
    putStrLn ("v_list1: " ++ show(v_list1))
    putStrLn ("v_list2: " ++ show(v_list2))
    putStrLn ("v_list3: " ++ show(v_list3))
    putStrLn ("v_list4: " ++ show(v_list4))
    putStrLn ("v_list5: " ++ show(v_list5))
    putStrLn ("v_list6: " ++ show(v_list6))
    
    putStrLn ("v_map1: " ++ show(v_map1))    
    putStrLn ("v_map2: " ++ show(v_map2))
    
    putStrLn ("v_tuple1: " ++ show(v_tuple1))    
    putStrLn ("v_tuple2: " ++ show(v_tuple2))    
    
    putStrLn ("v_tree1: " ++ show(v_tree1))    
    putStrLn ("v_tree2: " ++ show(v_tree2))        
    putStrLn ("v_tree1_n2: " ++ show(v_tree1_n2))    

    putStrLn ("v_csm1: " ++ show(v_csm))     
          
    --Beispiele für Gleichheit
    putStrLn ("184: " ++ (show (sp_eq v_string1 v_string2)))
    putStrLn ("185: " ++ (show (sp_eq "sad" v_string1)))
    putStrLn ("186: " ++ (show (sp_eq v_string1 "asd")))
    putStrLn ("188: " ++ (show (sp_eq v_list1 [3, (-2), 14, 5, 6])))
    putStrLn ("189: " ++ (show (sp_eq v_list1 [3, (-2), 5, 14, 6])))
    putStrLn ("190: " ++ (show (sp_eq v_list1 v_list7)))
    putStrLn ("192: " ++ (show (sp_eq v_tuple1 v_tuple3)))
    putStrLn ("193: " ++ (show (sp_eq v_tuple1 v_tuple4)))
    putStrLn ("195: " ++ (show (sp_eq v_map1 v_map3)))
    putStrLn ("196: " ++ (show (sp_eq v_map1 v_map4)))
    putStrLn ("197: " ++ (show (sp_eq v_map1 v_map5)))
    putStrLn ("199: " ++ (show (sp_neq true false)))
    putStrLn ("200: " ++ (show (sp_not (sp_or (sp_and true true) false))))
          
    --Anwendung von higher-order Funktionen
    putStrLn ("reduce: " ++ (show(reduce sp_max v_list1)))    
    putStrLn ("map: " ++ (show(map (squareAndAddA 3) v_list8)))
    putStrLn ("filter: " ++ (show(filter (biggerThanA 2) v_list8)))
    putStrLn ("firstMatch: " ++ (show(firstMatch (biggerThanA 5) v_list1)))
    putStrLn ("firstMatchIndex: " ++ (show(firstMatchIndex (biggerThanA 5) v_list1)))
    putStrLn ("combine: " ++ (show (combine tuple2 v_list8 v_list9)))
    
          