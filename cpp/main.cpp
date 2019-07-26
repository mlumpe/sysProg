#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_tokenize.cpp"
#include "Mod_parse.cpp"
#include "Mod_treeToString.cpp"


int main() {  
    
    //Code zum Testen    
    cout << "*** Tests ***" << endl;
    /**cout << "tokenize((((! a1) && 1 )-> (xyz || z)))" << endl;
    cout << tokenize("(((! a1) && 1 )-> (xyz || z))") << endl;
    cout << "tokenize(((abc && 0) -> x))" << endl;
    cout << tokenize("((abc && 0) -> x)") << endl;
    cout << "parse(((abc && 0) -> x))" << endl;*/
	Tuple2<Tree, Map<Node, String>> res = parse(tokenize("((abc && 0) -> x)"));
    cout << treeToString(get21(res)) << endl;
	cout << get22(res) << endl;
	
	res = parse(tokenize("(((! a1) && 1 )-> (xyz || z))"));
    cout << treeToString(get21(res)) << endl;
	cout << get22(res) << endl;
    
    return 0;
}
