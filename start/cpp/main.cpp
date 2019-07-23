#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_toBinary.cpp"
#include "Mod_fromBinary.cpp"
#include "Mod_addBinary.cpp"
#include "Mod_multBinary.cpp"


int main() {  
    
    //Code zum Testen    
    cout << "*** Tests ***" << endl;
    cout << "addBinary({0},{0})" << endl;
    cout << addBinary({0},{0}) << endl;
    cout << "addBinary({1,0,0},{1,1})" << endl;
    cout << addBinary({1,0,0},{1,1}) << endl;
    cout << "addBinary({1,0,1,1},{1,1,1,0})" << endl;
    cout << addBinary({1,0,1,1},{1,1,1,0}) << endl;
    cout << "" << endl;
    cout << "multBinary({0},{0})" << endl;
    cout << multBinary({0},{0}) << endl;
    cout << "multBinary({1},{1})" << endl;
    cout << multBinary({1},{1}) << endl;
    cout << "multBinary({1,0,1,1},{1,1,1,0})" << endl;
    cout << multBinary({1,0,1,1},{1,1,1,0}) << endl;
    cout << "" << endl;
    cout << "toBinary(0)" << endl;
    cout << toBinary(0) << endl;
    cout << "toBinary(1)" << endl;
    cout << toBinary(1) << endl;
    cout << "toBinary(2)" << endl;
    cout << toBinary(2) << endl;
    cout << "toBinary(3)" << endl;
    cout << toBinary(3) << endl;
    cout << "toBinary(4)" << endl;
    cout << toBinary(4) << endl;
    cout << "toBinary(20)" << endl;
    cout << toBinary(20) << endl;
    cout << "";
    cout << "fromBinary({0})" << endl;
    cout << fromBinary({0}) << endl;
    cout << "fromBinary({1})" << endl;
    cout << fromBinary({1}) << endl;
    cout << "fromBinary({1,0})" << endl;
    cout << fromBinary({1,0}) << endl;
    cout << "fromBinary({1,1})" << endl;
    cout << fromBinary({1,1}) << endl;
    cout << "fromBinary({1,0,0})" << endl;
    cout << fromBinary({1,0,0}) << endl;
    cout << "fromBinary({1,0,1,0,0})" << endl;
    cout << fromBinary({1,0,1,0,0}) << endl;
    
    return 0;
}