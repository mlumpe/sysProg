#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme


#include "Mod_vier.cpp"
#include "Mod_stream.cpp"
#include "Mod_flood.cpp"
#include "Mod_matrikelNr.cpp"


int main() {  

    //Code zum Testen    
    cout << "*** Tests ***" << endl;
    cout << "matrikelNr({123,125,127})" << endl;
    cout << matrikelNr({123,125,127}) << endl;
    cout << "matrikelNr({6123,243,125})" << endl;
    cout << matrikelNr({6123,243,125}) << endl;
    cout << "flood(wbwbwbbwbwbw, 3, 1, 2)" << endl;
    cout << flood("wbwbwbbwbwbw", 3, 1, 2) << endl;
    cout << "flood(bbwwbw, 3, 1, 0)" << endl;
    cout << flood("bbwwbw", 3, 1, 0) << endl;
    cout << "flood(bbbbbbbbwwwbbwwbbwwbbwwb, 4, 3, 4)" << endl;
    cout << flood("bbbbbbbbwwwbbwwbbwwbbwwb", 4,3,4) << endl;
	cout << "vier({0,0,-1,1,-2,3,-3})" << endl;
	cout << vier({0,0,-1,1,-2,3,-3}) << endl;
	cout << "vier({-5,2,-4,2,-3,2,-1,2})" << endl;
	cout << vier({-5,2,-4,2,-3,2,-1,2}) << endl;
	cout << "vier({0,1})" << endl;
	cout << vier({0,1}) << endl;
	cout << "stream(abc, d)" << endl;
	cout << stream("abc", "d") << endl;
	cout << "stream(aaaa, aa)" << endl;
	cout << stream("aaaa", "aa") << endl;
	cout << "stream(caaca, *a)" << endl;
	cout << stream("caaca", "*a") << endl;
	cout << "stream(abacaaa, a*a)" << endl;
	cout << stream("abacaaa", "a*a") << endl;
	cout << "stream(abacaaa, *)" << endl;
	cout << stream("abacaaa", "*") << endl;
	cout << "stream(a, ab)" << endl;
	cout << stream("a", "ab") << endl;
	
    
    
    cout << "firstChild(Tree, Node)" << endl;
    cout << "firstChild(t2, v25)" << endl;
    cout << firstChild(t2, v25) << endl;
    cout << "firstChild(t2, v23)" << endl;
    cout << firstChild(t2, v23) << endl;
    cout << "firstChild(t2, v22)" << endl;
    cout << firstChild(t2, v22) << endl;
    
    //cout << "nextSibling(Tree, Node)" << endl;
    //cout << nextSibling(t2, v26) << endl;
    
    cout << "allNodes(Tree)" << endl;
    cout << "allNodes(t1)" << endl;
    cout << allNodes(t1) << endl;
    cout << "allNodes(t2)" << endl;
    cout << allNodes(t2) << endl;
    cout << "allNodes(t4)" << endl;
    cout << allNodes(t4) << endl;
    cout << "allNodes(t5)" << endl;
    cout << allNodes(t5) << endl;

    cout << "removeSubtree(Tree, Node)" << endl;
    cout << "removeSubtree(t2, v5)" << endl;
    cout << removeSubtree(t2, v25) << endl;
    cout << "removeSubtree(t2, v2)" << endl;
    cout << removeSubtree(t2, v22) << endl;
    cout << "removeSubtree(t1, v1)" << endl;
    cout << removeSubtree(t1, v11) << endl;
    
    //cout << depth(t5) << endl;
    
    return 0;
}
