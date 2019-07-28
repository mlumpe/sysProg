#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_tokenize.cpp"
#include "Mod_parse.cpp"
#include "Mod_treeToString.cpp"
#include "Mod_eval.cpp"
#include "Mod_satisfiable.cpp"


int main() {  
    
    //Code zum Testen    
    cout << "*** Tests Tokenize***" << endl;
    cout << "tokenize((((! a1) && 1 )-> (xyz || z)))" << endl;
    cout << tokenize("(((! a1) && 1 )-> (xyz || z))") << endl;
    cout << "tokenize(((abc && 0) -> x))" << endl;
    cout << tokenize("((abc && 0) -> x)") << endl << endl;
    
    cout << "*** Tests Parse & Eval & Satisfiable ***";
    cout << "((abc && 0) -> x)" << endl;
	Tuple2<Tree, Map<Node, String>> res = parse(tokenize("((abc && 0) -> x)"));
    cout << treeToString(get21(res));
	cout << get22(res) << endl;
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
    cout << get22(eval(res)) << endl;
    
    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;
	
    cout << "(((! a1) && 1 )-> (xyz || z))" << endl;
	res = parse(tokenize("(((! a1) && 1 )-> (xyz || z))"));
    cout << treeToString(get21(res));
	cout << get22(res) << endl;    
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
	cout << get22(eval(res)) << endl;

    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;
    
    cout << "(((! 1) && 1 )-> (xyz || z))" << endl;
	res = parse(tokenize("(((! 1) && 1 )-> (xyz || z))"));
    cout << treeToString(get21(res));
	cout << get22(res) << endl;    
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
	cout << get22(eval(res)) << endl;

    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;
    
    cout << "(!(!(!(!(!1)))))" << endl;
	res = parse(tokenize("(!(!(!(!(!1)))))"));
    cout << treeToString(get21(res));
	cout << get22(res) << endl;    
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
	cout << get22(eval(res)) << endl;
    
    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;
    
    // 3-SAT Bespiel mit erfüllbarer Fromel
    /*cout << "(((((!x1) || x2) || x3) && ((x2 || (!x3)) || x4)) && (x1 || (!x2)))" << endl;
    res = parse(tokenize("(((((!x1) || x2) || x3) && ((x2 || (!x3)) || x4)) && (x1 || (!x2)))"));
    cout << treeToString(get21(res));
    cout << get22(res) << endl;
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
    cout << get22(eval(res)) << endl;
    
    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;*/
    
    cout << "((a || (!a)) -> ((a2 && (!a2)) || (a3 && a3)))" << endl;
    res = parse(tokenize("((a || (!a)) -> ((a2 && (!a2)) || (a3 && a3)))"));
    cout << treeToString(get21(res));
    cout << get22(res) << endl;
    
    cout << "Eval Tree & Map:" << endl << treeToString(get21(eval(res)));
    cout << get22(eval(res)) << endl;
    
    cout << "satisfiable: " << (satisfiable(res) == 1 ? "true": "false") << endl << endl;

    return 0;
}
