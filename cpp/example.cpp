#include "splib.cpp"
#include "types.cpp"


/*
  Nachfolgend drei Beispiele für higher-order Funktionen, 
  also Funktionen, welche Funktionen als Eingabeparameter
  bekommen oder selbst eine Funktion zurückgeben. 
  
  Der Typ einer Funktion mit Signatur a1 -> a2 -> a3 -> a4 
  ist function<a4(a1,a2,a3)>
*/


String doSomething(Int x, function<String(Int)> f) {
    return f(x);
}


function<Int(Int)> squareAndAddA(Int a) { 
    return [a](Int x) {        
        return (x*x)+a;
    };
}

function<Bool(Int)> biggerThanA(Int a) {
    return [a](Int x) {
        return sp_gt(x,a);
    };    
}


int main() {  
        
    //Konstruieren der Datentypen aus der splib
    Int v_int1, v_int2;
    Char v_char;
    Bool v_bool1, v_bool2;
    String v_string1, v_string2;    
    
    v_int1 = 12;
    v_int2 = (-4); 
    v_char = 'x';
    v_bool1 = true;
    v_bool2 = false;
    v_string1 = "asd";
    v_string2 = "test 1234!";
    
    
    //List
    List<Int> v_list1, v_list7, v_list8;
    List<List<Int>> v_list2;
    List<Bool> v_list3, v_list6;
    List<Char> v_list4, v_list9;
    List<String> v_list5;
    
    v_list1 = {3,(-2),14,5,6};
    v_list2 = {{1,2},{3,4,5},{},{6}};
    v_list3 = {};
    v_list4 = {'a','b','c'};
    v_list5 = {"str1","str2","str3"};
    v_list6 = {true,false,true};
    v_list7 = {3,(-2),14,5,6};
    v_list8 = {0,1,2,3,4,5};
    v_list9 = {'a','b','c','d','e','f'};
    
    
    //Map    
    Map<Int,String> v_map1, v_map3, v_map4, v_map5;
    Map<Char,Bool> v_map2;    
    
    /*
      Compiler kann Signatur von emptyMap nicht selbst erkennen, 
      deshalb muss die Funtion emptyMap mit "<Int,String>" 
      gecastet werden 
    */
    v_map1 = emptyMap<Int,String>(); 
    
    /*
      ein String-Literal hat Typ "const char*" und der Compiler 
      weiß nicht, dass es als String interpretiert werden soll; 
      deshalb muss auch hier gecastet werden
    */
    v_map1 = setImage<Int,String>(v_map1,1,"one"); 
    
    //Alternative: indirekt casten durch s2s
    v_map1 = setImage(v_map1,2,s2s("two"));             
    v_map1 = setImage(v_map1,3,s2s("three"));
    
    String v_map1_one = "one";
    
    v_map2 = emptyMap<Char,Bool>(); 
    v_map2 = setImage(v_map2,'a',true);
    v_map2 = setImage(v_map2,'b',false);    
    v_map2 = setImage(v_map2,'c',true);
    v_map2 = setImage(v_map2,'d',false);
    v_map2 = setImage(v_map2,'e',true);           

    v_map3 = emptyMap<Int,String>(); 
    v_map3 = setImage(v_map3,3,s2s("three"));
    v_map3 = setImage(v_map3,2,s2s("two"));  
    v_map3 = setImage(v_map3,1,s2s("one"));         
                  
    v_map4 = emptyMap<Int,String>(); 
    v_map4 = setImage(v_map4,3,s2s("three"));
    v_map4 = setImage(v_map4,2,s2s("two"));  
    v_map4 = setImage(v_map4,1,s2s("not one"));     

    v_map5 = emptyMap<Int,String>(); 
    
    //Tuple
    Tuple2<String,Int> v_tuple1, v_tuple3, v_tuple4;
    Tuple4<String,Int,Int,Bool> v_tuple2;        
    
    v_tuple1 = tuple2(removeLast(removeFirst(show("tuple1"))),34);   
    v_tuple2 = tuple4(removeLast(removeFirst(show("tuple2"))),(-3),4,true);       
    v_tuple3 = tuple2(removeLast(removeFirst(show("tuple3"))),34);  
    v_tuple4 = tuple2(removeLast(removeFirst(show("tuple4"))),1);  
    
    
    //Tree & Node
    Tree v_tree1,v_tree2;
    Node v_tree1_n1, v_tree1_n2, v_tree1_n3;
    
    v_tree1 = newTree(); 
    v_tree1_n1 = lastNode(v_tree1);
    
    v_tree1 = addLeaf(v_tree1,v_tree1_n1);
    v_tree1_n2 = lastNode(v_tree1);

    v_tree1 = addLeaf(v_tree1,v_tree1_n1);
    v_tree1_n3 = lastNode(v_tree1);    
    
    v_tree1 = addLeaf(v_tree1,v_tree1_n2);
    v_tree1 = addLeaf(v_tree1,v_tree1_n3);
    v_tree1 = addLeaf(v_tree1,v_tree1_n3);
    
               
    v_tree2 = newTreeOwn(createNode(1));
    v_tree2 = addOwnLeaf(v_tree2,createNode(1),createNode(2));
    v_tree2 = addOwnLeaf(v_tree2,createNode(1),createNode(5));
    v_tree2 = addOwnLeaf(v_tree2,createNode(2),createNode(3));
    v_tree2 = addOwnLeaf(v_tree2,createNode(2),createNode(4));
    v_tree2 = addOwnLeaf(v_tree2,createNode(5),createNode(6));
    v_tree2 = addOwnLeaf(v_tree2,createNode(5),createNode(7));           
    
    
    //CSMInstance 
    CSMInstance v_csm;
    List<String> v_csm_a = {"cece","ce","ce","ce"};
    List<String> v_csm_b = {"ce","cec","ece","ce"};
    v_csm = createCSM(v_csm_a,v_csm_b);
    
    
    //Ausgabe       
    cout << "v_int1: " << show(v_int1) << endl;
    cout << "v_int2: " << show(v_int2) << endl;
    cout << "v_char: " << show(v_char) << endl;
    cout << "v_bool1: " << show(v_bool1) << endl;
    cout << "v_bool2: " << show(v_bool2) << endl;
    cout << "v_string1: " << show(v_string1) << endl;
    cout << "v_string2: " << show(v_string2) << endl;
    
    cout << "v_list1: " << show(v_list1) << endl;
    cout << "v_list2: " << show(v_list2) << endl;
    cout << "v_list3: " << show(v_list3) << endl;
    cout << "v_list4: " << show(v_list4) << endl;
    cout << "v_list5: " << show(v_list5) << endl;
    cout << "v_list6: " << show(v_list6) << endl;
    
    cout << "v_map1: " << show(v_map1) << endl;    
    cout << "v_map2: " << show(v_map2) << endl;
    
    cout << "v_tuple1: " << show(v_tuple1) << endl;    
    cout << "v_tuple2: " << show(v_tuple2) << endl;    
    
    cout << "v_tree1: " << show(v_tree1) << endl;    
    cout << "v_tree2: " << show(v_tree2) << endl;        
    cout << "v_tree1_n2: " << show(v_tree1_n2) << endl;    

    cout << "v_csm1: " << show(v_csm) << endl;    
    
    
    //Beispiele für Gleichheit
    cout << __LINE__ << ": " << show(sp_eq(v_string1,v_string2)) << endl; 
    cout << __LINE__ << ": " << show(sp_eq<String>("sad",v_string1)) << endl; 
    cout << __LINE__ << ": " << show(sp_eq<String>(v_string1,"asd")) << endl; 
    
    cout << __LINE__ << ": " << show(sp_eq<List<Int>>(v_list1,{3,(-2),14,5,6})) << endl; 
    cout << __LINE__ << ": " << show(sp_eq<List<Int>>(v_list1,{3,(-2),5,14,6})) << endl; 
    cout << __LINE__ << ": " << show(sp_eq(v_list1,v_list7)) << endl; 
    
    cout << __LINE__ << ": " << show(sp_eq(v_tuple1,v_tuple3)) << endl; 
    cout << __LINE__ << ": " << show(sp_eq(v_tuple1,v_tuple4)) << endl; 
    
    cout << __LINE__ << ": " << show(sp_eq(v_map1,v_map3)) << endl; 
    cout << __LINE__ << ": " << show(sp_eq(v_map1,v_map4)) << endl;     
    cout << __LINE__ << ": " << show(sp_eq(v_map1,v_map5)) << endl;     
           
    cout << __LINE__ << ": " << show(sp_neq(true,false)) << endl;     
    cout << __LINE__ << ": " << show(sp_not(sp_or(sp_and(true,true),false))) << endl;     
             
    
    //Anwendung von higher-order Funktionen
    String res;
    
    //reduce 
    res = show(reduce<Int>(sp_max,v_list1));    
    cout << "reduce: " << res << endl;  

    //map
    res = show(map<Int,Int>(squareAndAddA(3),v_list8));    
    cout << "map: " << res << endl;  
    
    //filter 
    res = show(filter<Int>(biggerThanA(2),v_list8));    
    cout << "filter: " << res << endl;  
        
    //getFirstMatch
    res = show(firstMatch<Int>(biggerThanA(5),v_list1));    
    cout << "firstMatch: " << res << endl; 
    
    //getFirstMatchIndex
    res = show(firstMatchIndex<Int>(biggerThanA(5),v_list1));    
    cout << "firstMatchIndex: " << res << endl;     
    
    //combine
    res = show(combine<Int,Char,Tuple2<Int,Char>>(tuple2<Int,Char>,v_list8,v_list9));    
    cout << "combine: " << res << endl;  
        
    
    return 0;
}