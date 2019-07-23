#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme

#include "Mod_absolute.cpp"
#include "Mod_factorial.cpp"
#include "Mod_fibonacci.cpp"
#include "Mod_isPrime.cpp"
#include "Mod_nthPrime.cpp"
#include "Mod_toBinary.cpp"
#include "Mod_fromBinary.cpp"
#include "Mod_addBinary.cpp"
#include "Mod_multBinary.cpp"
#include "Mod_addKAry.cpp"


int main() {  
	/* Tree t1 */
    /**Tree t1 = newTree();
    Node v11 = root(t1);*/

    /* Tree t2 */
    /**Tree t2 = newTree();
    Node v21 = root(t2);
    t2 = addLeaf(t2, v21);
    t2 = addLeaf(t2, v21);
    Node v22 = get(children(t2, v21), 0);
    Node v23 = get(children(t2, v21), 1);
    t2 = addLeaf(t2, v22);
    t2 = addLeaf(t2, v22);
    Node v24 = get(children(t2, v21), 0);
    Node v25 = get(children(t2, v21), 1);
    t2 = addLeaf(t2, v25);
    t2 = addLeaf(t2, v25);
    t2 = addLeaf(t2, v25);
    Node v26 = get(children(t2, v21), 0);
    Node v27 = get(children(t2, v21), 1);
    Node v28 = get(children(t2, v21), 2);
    t2 = addLeaf(t2, v23);
    Node v29 = get(children(t2, v23), 0);*/

    /* Tree t3*/
    /**Node v35 = createNode(5);
    Node v36 = createNode(6);
    Node v37 = createNode(7);
    Node v38 = createNode(8);
    Tree t3 = newTreeOwn(v35);
    t3 = addOwnLeaf(t3, v35, v36);
    t3 = addOwnLeaf(t3, v35, v37);
    t3 = addOwnLeaf(t3, v35, v38);*/

    /* Tree t4 */
    /**Tree t4 = newTree();
    Node v41 = root(t4);
    t4 = addLeaf(t4, v41);
    t4 = addLeaf(t4, v41);
    Node v42 = get(children(t4, v41), 0);
    Node v43 = get(children(t4, v41), 1);
    t4 = addLeaf(t4, v42);
    t4 = get(children(t4, v42), 0);
    Node v49 = createNode(9);
    t4 = addOwnLeaf(t4, v43, v49);*/

    /* Tree t5 */
    
    
    //Code zum Testen    
    cout << "*** Tests ***" << endl;
	cout << "absolute(int)" << endl;
    cout << "absolute(-3)" << endl;
    cout << absolute(-3) << endl;
    cout << "absolute(2)" << endl;
    cout << absolute(2) << endl;
    cout << "absolute(0)" << endl;
    cout << absolute(0) << endl;
    
    cout << endl;
    cout << "factorial(int)" << endl;
    cout << "factorial(0)" << endl;
    cout << factorial(0) << endl;
    cout << "factorial(1)" << endl;
    cout << factorial(1) << endl;
    cout << "factorial(4)" << endl;
    cout << factorial(4) << endl;
    cout << "factorial(5)" << endl;
    cout << factorial(5) << endl;
    
    cout << endl;
    cout << "fibonacci(int)" << endl;
    cout << "fibonacci(0)" << endl;
    cout << fibonacci(0) << endl;
    cout << "fibonacci(1)" << endl;
    cout << fibonacci(1) << endl;
    cout << "fibonacci(2)" << endl;
    cout << fibonacci(2) << endl;
    cout << "fibonacci(3)" << endl;
    cout << fibonacci(3) << endl;
    cout << "fibonacci(6)" << endl;
    cout << fibonacci(6) << endl;
    
    cout << endl;
    cout << "isPrime(int)" << endl;
    cout << "isPrime(0)" << endl;
    cout << isPrime(0) << endl;
    cout << "isPrime(1)" << endl;
    cout << isPrime(1) << endl;
    cout << "isPrime(2)" << endl;
    cout << isPrime(2) << endl;
    cout << "isPrime(3)" << endl;
    cout << isPrime(3) << endl;
    cout << "isPrime(4)" << endl;
    cout << isPrime(4) << endl;
    cout << "isPrime(17)" << endl;
    cout << isPrime(17) << endl;

    cout << endl;
    cout << "nthPrime(int)" << endl;
    cout << "nthPrime(1)" << endl;
    cout << nthPrime(1) << endl;
    cout << "nthPrime(2)" << endl;
    cout << nthPrime(2) << endl;
    cout << "nthPrime(3)" << endl;
    cout << nthPrime(3) << endl;
    cout << "nthPrime(10)" << endl;
    cout << nthPrime(10) << endl;

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
    cout << "addKAry(10,{1,2,3},{9,7})" << endl;
    cout << addKAry(10,{1,2,3},{9,7}) << endl;
    cout << "addKAry(16,{15,1,3},{9,4,12,0})" << endl;
    cout << addKAry(16,{15,1,3},{9,4,12,0}) << endl;
    
    return 0;
}