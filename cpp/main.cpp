#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_tokenize.cpp"


int main() {  
    
    //Code zum Testen    
    cout << "*** Tests ***" << endl;
    cout << "tokenize((((! a1) && 1 )-> (xyz || z)))" << endl;
    cout << tokenize("(((! a1) && 1 )-> (xyz || z))") << endl;
    cout << "tokenize(((abc && 0) -> x))" << endl;
    cout << tokenize("((abc && 0) -> x)") << endl;
    
    return 0;
}
