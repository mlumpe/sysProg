#include "splib.cpp"
#include "types.cpp"
#include <cassert>

//Einbinden der selbst geschriebenen Programme
/* AB1
 #include "Mod_fizzBuzz.cpp"
#include "Mod_foliate.cpp"
#include "Mod_multiplyList.cpp"
#include "Mod_generateSequence.cpp"
#include "Mod_removeDuplicates.cpp"
#include "Mod_csmAlg.cpp"
 */
#include "Mod_absolute.cpp"
#include "Mod_factorial.cpp"
#include "Mod_fibonacci.cpp"
#include "Mod_Prime.cpp"


/*int f1(int n) {return 2*n-1;}
int f2(int n) {return 2 << (n-1);}
Char f3(int n) {return 'z';}*/

int main() {
    /*List<Int> l = {1,1,6,3,1,3};
    List<Char> k = {'a','b','a','b','c','a','b'};
    List<Int> j = {};
    
    CSMInstance x1_csm;
    List<String> x1_csm_a = {"ab","cd"};
    List<String> x1_csm_b = {"a","b","c","d"};
    x1_csm = createCSM(x1_csm_a,x1_csm_b);
    
    
    CSMInstance x2_csm;
    List<String> x2_csm_a = {};
    List<String> x2_csm_b = {};
    x2_csm = createCSM(x2_csm_a,x2_csm_b);
    
    
    CSMInstance x3_csm;
    List<String> x3_csm_a = {"aa","a"};
    List<String> x3_csm_b = {"aac"};
    x3_csm = createCSM(x3_csm_a,x3_csm_b);
    
    //Code zum Testen    
    cout << "*** Tests ***" << endl;
    cout << "fizzBuzz(30): " << endl;
    cout << fizzBuzz(30) << endl;
    cout << endl;
    cout << "foliate({4,1,2,3}):" << endl;
    cout << foliate({4,1,2,3}) << endl;
    
    cout << endl;
    cout << "multiplyList(List, int)" << endl;
    cout << "multiplyList({1,2,3}, 2): " << endl;
    List<Int> li = {1,2,3};
    cout << multiplyList(li, 2) << endl;
    cout << "multiplyList({a,b}, 3): " << endl;
    List<Char> lc = {'a','b'};
    cout << multiplyList(lc, 3) << endl;
    cout << "multiplyList({{1,2},{3},{4,5}}, 4): " << endl;
    List<List<Int>> lli = {{1,2},{3},{4,5}};
    cout << multiplyList(lli, 4) << endl;
    cout << "multiplyList({}, 9): " << endl;
    List<Int> le = {};
    cout << multiplyList(le, 9) << endl;
    
    cout << endl;
    cout << "generateSequence(Func, List)" << endl;
    cout << "generateSequence(f1, 3)" << endl;
    cout << generateSequence(f1, 3) << endl;
    cout << "generateSequence(f2, 4)" << endl;
    cout << generateSequence(f2, 4) << endl;
    cout << "generateSequence(f1, 3)" << endl;
    cout << generateSequence(f3, 5) << endl;
    
    cout << endl;
    cout << "removeDuplicates({1,1,6,3,1,3}):" << endl;
    cout << removeDuplicates(l) << endl;
    cout << "removeDuplicates({a,b,a,b,c,a,b}):" << endl;
    cout << removeDuplicates(k) << endl;
    cout << "removeDuplicates({})" << endl;
    cout << removeDuplicates(j) << endl;
    
    cout << endl;
    cout << "csmAlg(x1_csm)" << endl;
    cout << csmAlg(x1_csm) << endl;
    cout << "csmAlg(x2_csm)" << endl;
    cout << csmAlg(x2_csm) << endl;
    cout << "csmAlg(x3_csm)" << endl;
    cout << csmAlg(x3_csm) << endl;*/
    
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
    assert(factorial(0) == 1);
    cout << "factorial(1)" << endl;
    cout << factorial(1) << endl;
    assert(factorial(1) == 1);
    cout << "factorial(4)" << endl;
    cout << factorial(4) << endl;
    assert(factorial(4) == 24);
    cout << "factorial(5)" << endl;
    cout << factorial(5) << endl;
    assert(factorial(5) == 120);
    
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

    return 0;
}
