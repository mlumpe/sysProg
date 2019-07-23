/*
   splib v1.0
   In dieser Datei sollte nichts verändert werden!
*/

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;

// Type aliases
using Int = int;
using Bool = bool;
using Char = char;
using String = string;
template<class T> using List = vector<T>;

void panic(String msg) {
    cerr << "ERROR: " << msg << endl;
    exit(1);
}

//generic string output for variables of functional type 
template <typename T1, typename ... Ts>
ostream& operator <<(ostream& out, const function<T1(Ts...)>& obj ) {    
    out << "Function";
    return out;
}

template <typename T1, typename ... Ts>
String show(function<T1(Ts...)> obj) {    
    return "Function";    
}


String show(Int x) {       
    ostringstream stream;
    stream << x;
    return stream.str();        
}

String show(Bool x) {       
    String res;
    if(x) {
        res = "True";
    } else {
        res = "False";
    }
    return res;
}

String show(Char x) {       
    String res = "'";
    res.push_back(x);
    res.push_back('\'');    
    return res;
}

String show(String x) {         
    String res = "\"";
    res += x;
    res += "\"";
    return res;
}

String show(const char* x) {    
    String y = x;
    return show(y);
}

String c2s(Char x) {
    String y = "";
    y.push_back(x);
    return y;
}

String s2s(String x) {
    return x;
}


template <typename T>
bool operator!=(const T& lhs, const T& rhs) { return !(lhs == rhs); }


/*
    List functions
*/ 

template <typename T>
String show(List<T> obj) {
    if(obj.empty()) {
        return "[]";
    }
        
    String out = "[";
    for(int i=0; i<obj.size(); i++) {         
        out += show(obj.at(i));
        if(i < obj.size()-1) {
            out += ",";
        }
    }
    out += "]";
    return out;        
}

template<typename T>
ostream& operator<<(ostream& out, const List<T>& obj ) {        
    out << show(obj);
    return out;
}


template <typename T>
T get(List<T> list, int index) {
   return list.at(index);
}

Char get(String list, int index) {
   return list.at(index);
}

template <typename T>
List<T> set(List<T> list, int index, T val) {
    list.at(index) = val;    
    return list;
}

String set(String list, int index, Char val) {
    list.at(index) = val;    
    return list;
}

List<String> set(List<String> list, int index, const char* val) {
    return set(list,index,String(val));
}

template <typename T>
int length(List<T> list) {
    return list.size();
}

int length(String list) {
    return list.size();
}

template <typename T>
bool empty(List<T> list) {
    return list.empty();
}

bool empty(String list) {
    return list.empty();
}

template <typename T>
T first(List<T> list) {
    return list.front();
}

Char first(String list) {
    return list.front();
}

template <typename T>
T last(List<T> list) {    
    return list.back();
}

Char last(String list) {    
    return list.back();
}

template <typename T>
List<T> append(List<T> list, T val) {
    list.push_back(val);
    return list;
}

String append(String list, Char val) {
    list.push_back(val);
    return list;
}

List<String> append(List<String> list, const char* val) {    
    return append(list,String(val));    
}

template <typename T>
List<T> insert(List<T> list, int index, T val) {    
    if(index == length(list)) return append(list,val);
    
    List<T> new_list;    
    for(int i=0; i < length(list); i++) {
        if(i==index) {
            new_list = append(new_list,val);
        }
        new_list = append(new_list, get(list, i));
    }
    return new_list;
}

String insert(String list, int index, Char val) {
    if(index == length(list)) return append(list,val);
    
    String new_list;    
    for(int i=0; i < length(list); i++) {
        if(i==index) {
            new_list = append(new_list,val);
        }
        new_list = append(new_list, get(list, i));
    }
    return new_list;
}

List<String> insert(List<String> list, int index, const char* val) {
    return insert(list,index,String(val));
}

template <typename T>
List<T> prepend(List<T> list, T val) {
    return insert(list,0,val);
}

String prepend(String list, Char val) {
    return insert(list,0,val);
}

List<String> prepend(List<String> list, const char* val) {
    return prepend(list,String(val));
}

template <typename T>
List<T> remove(List<T> list, int index) {
    List<T> new_list;    
    for(int i=0; i < length(list); i++) {
        if(i!=index) {
            new_list = append(new_list, get(list, i));
        }        
    }
    return new_list;
}

String remove(String list, int index) {
    String new_list;    
    for(int i=0; i < length(list); i++) {
        if(i!=index) {
            new_list = append(new_list, get(list, i));
        }        
    }
    return new_list;
}

template <typename T>
List<T> removeFirst(List<T> list) {
    return remove(list,0);
}

String removeFirst(String list) {
    return remove(list,0);
}

template <typename T>
List<T> removeLast(List<T> list) {
    return remove(list,length(list)-1);
}

String removeLast(String list) {
    return remove(list,length(list)-1);
}

template <typename T>
List<T> join(List<T> list, List<T> list2) {
    for(int i=0; i < length(list2); i++) {
        list = append(list,get(list2, i));
    }
    return list;
}

String join(String list, String list2) {
    for(int i=0; i < length(list2); i++) {
        list = append(list,get(list2, i));
    }
    return list;
}

template <typename T>
bool contains(List<T> list, T val) {    
    for(int i=0; i<length(list); i++) {
        if(get(list,i) == val) {
            return true;
        }
    }    
    return false;
}

bool contains(String list, Char val) {    
    for(int i=0; i<length(list); i++) {
        if(get(list,i) == val) {
            return true;
        }
    }    
    return false;
}

template <typename T>
List<T> sublist(List<T> list, int start, int length) {    
    List<T> res; 
    
    for(int i=0; i<length; i++) {
        res = append(res, get(list,(i+start)));                       
    }    
    return res;
}

String sublist(String list, int start, int length) {    
    String res; 
    
    for(int i=0; i<length; i++) {
        res = append(res, get(list,(i+start)));                       
    }    
    return res;
}

template <typename T>
List<T> reverse(List<T> list) {    
    List<T> res; 
    
    for(int i=(length(list)-1); i>=0; i--) {
        res = append(res, get(list,i));                       
    }    
    return res;
}

String reverse(String list) {    
    String res; 
    
    for(int i=(length(list)-1); i>=0; i--) {
        res = append(res, get(list,i));                       
    }    
    return res;
}

//Compares if two lists have the same elements ignoring order
//The count of elements is important, i.e.
// setCompare({1,1},{1}) = false 
template <typename T>
Bool setCompare(List<T> list1, List<T> list2) {
    if(length(list1) != length(list2)) {
        return false;
    }
    
    T x;
    bool found;
    while(length(list1) > 0) {
        x = first(list1);
        list1 = removeFirst(list1);
        found = false;
        for(int i=0;i<length(list2);i++) {
            if(x == get(list2,i)) {
                list2 = remove(list2,i);
                found = true;
            }
        }
        if(!found) {
            return false;
        }
    }
    return true;
}


/*
    Higher-order functions
*/
template <typename T1, typename T2>
List<T2> map(function<T2(T1)> f, List<T1> list) {
    List<T2> list2;
    for(int i=0; i < length(list); i++) {
        list2 = append(list2, f(get(list,i)));
    }
    return list2;
}

template <typename T>
T reduce(function<T(T,T)> f, List<T> list) {
    if(length(list)==0) {
        panic("empty list passed to reduce");
    }        
    
    T x1, x2;
    
    while(length(list)>1) {
        x1 = first(list);       
        list = removeFirst(list);
        x2 = first(list);        
        list = removeFirst(list);        
        list = prepend(list,f(x1,x2));        
    }    
    return first(list);    
}

template <typename T>
List<T> filter(function<Bool(T)> f, List<T> list) {
    List<T> list2;
    T cur;
    
    while(!empty(list)) {
        cur = first(list);
        list = removeFirst(list);
        if(f(cur)) {
            list2 = append(list2,cur);
        }
    }
    
    return list2;
}


template <typename T>
Int firstMatchIndex(function<Bool(T)> f, List<T> list) {    
    int res=-1;
    for(int i=0; i<length(list); i++) {
        if(f(get(list,i))) {
            res = i;
            break;
        }
    }
    
    if(res==-1) {
        panic("firstMatchIndex not match found");
    }
    return res;
}

template <typename T>
T firstMatch(function<Bool(T)> f, List<T> list) {
   return get(list,firstMatchIndex(f,list));
}

template <typename T1, typename T2, typename T3>
List<T3> combine(function<T3(T1,T2)> f, List<T1> list1, List<T2> list2) {
    if(length(list1) != length(list2)) {
        panic("combine called with lists of different lengths");
    }
    
    List<T3> res;
    for(int i=0; i<length(list1); i++) {
        res = append(res,f(get(list1,i),get(list2,i)));
    }
    return res;
}


/*
    Arithmetic & Logic
*/
template <typename T>
Bool sp_eq(T x, T y) {
    return (x==y);
}

template <typename T>
Bool sp_neq(T x, T y) {
    return !(x==y);
}

Bool sp_lt(Int x, Int y) {
    return (x<y);
}

Bool sp_gt(Int x, Int y) {
    return (x>y);
}

Bool sp_leq(Int x, Int y) {
    return (x<=y);
}

Bool sp_geq(Int x, Int y) {
    return (x>=y);
}

Int sp_add(Int x, Int y) {
    return (x+y);
}

Int sp_minus(Int x, Int y) {
    return (x-y);
}

Int sp_mult(Int x, Int y) {
    return (x*y);
}

Int sp_div(Int x, Int y) {
    return (x/y);
}

Int sp_mod(Int x, Int y) {
    return (x%y);
}

Int sp_max(Int x, Int y) {
    if(x>y) {
        return x;
    } else {
        return y;
    }
}

Int sp_min(Int x, Int y) {
    if(x<y) {
        return x;
    } else {
        return y;
    }
}

Int sp_pow(Int x, Int y) {
    return pow(x,y);
}

Bool sp_and(Bool a, Bool b) {
    return a && b;
}

Bool sp_or(Bool a, Bool b) {
    return a || b;
}

Bool sp_not(Bool a) {
    return !a;
}

template <typename T>
T sp_if(Bool p, T x, T y) {
    if(p) {
        return x;
    } else {
        return y;
    }
}


/*
    Tree data type
*/
struct Node { Int id; };
bool operator==(const Node& lhs, const Node& rhs) { return lhs.id == rhs.id; }
bool operator!=(const Node& lhs, const Node& rhs) { return lhs.id != rhs.id; }
String show(Node node) { return show(node.id); }; 
ostream& operator<<(ostream& out, const Node& node) { out << show(node); return out; }
//ostream& operator<<(ostream& out, const Node& node) { out << node.id; return out; }


Node createNode(Int y) {
    Node x;
    x.id = y;
    return x;
}

class Tree {
    private:    
    Node rootNode;
    List<Node> nodes;
    List<List<Node>> clist;    
    
    int index(Node v) const {
        for(int i=0; i < length(nodes); i++) {
            if(v == get(nodes,i)) {
                return i;
            }
        }
        String vstr = to_string(v.id);
        panic("index(Node v="+vstr+"): node not found");
        return 0;
    }
    
    int nextId() const {
        auto anon = [](Node u) { return u.id; };
        auto mymax = [](Int x, Int y) { return max(x,y); };
        List<Int> ids = map<Node,Int>(anon,nodes);
        return reduce<Int>(mymax,ids)+1;        
    }    
    
    Tree(Node rootNode, List<Node> nodes, List<List<Node>> clist) : rootNode(rootNode), nodes(nodes), clist(clist) {
        
    }
    
    public:    
    Tree() {     
        Node r;
        r.id = 1;   
        rootNode = r;
        nodes = {r};
        clist = {List<Node>({})};                 
    }
    
    Tree(Node r) {             
        rootNode = r;
        nodes = {r};
        clist = {List<Node>({})};                 
    }    
    
    Node root() const {
        return rootNode;
    }
                    
    bool isRoot(Node v) const {
        return v == root();
    }
    
    bool isLeaf(Node v) const {
        return length(get(clist,index(v))) == 0;
    }    
    
    Node parent(Node v) const {
        for(int i=0; i<length(nodes); i++) {
            List<Node> c = get(clist,i);
            for(int j=0; j<length(c); j++) {
                if(v == get(c,j)) {
                    return get(nodes,i);
                }
            }
        }
        //panic
        String vstr = to_string(v.id);
        panic("parent(Node v = "+vstr+") is root and thus has no parent!");        
        return root();
    }    
    
    Node lastNode() const {
        return last(nodes);
    }
    
    List<Node> children(Node v) const {
        return get(clist,index(v));
    }

    Int size() const {
        return length(nodes);
    }
            
    Tree addOwnLeaf(Node v, Node w) const {                
        //add to list of nodes and append empty list to children
        List<Node> nodes2 = append(nodes,w);
        List<List<Node>> clist2 = append(clist,List<Node>({}));
        
        //add w to children list of v
        int i = index(v);
        List<Node> nv = append(get(clist,i),w);
        clist2 = set(clist2,i,nv);                               
        
        Tree t2(rootNode,nodes2,clist2);
        
        return t2;       
    }
    
    Tree addLeaf(Node v) const {  
        //new node with id counter
        Node w;
        w.id = nextId();
        
        return addOwnLeaf(v,w);        
    }    
        
    Tree removeLeaf(Node v) const {
        if(!isLeaf(v)) {
            String vstr = to_string(v.id);
            panic("removeLeaf(Node v = "+vstr+") is no leaf");
        }
                       
        List<Node> nodes2 = remove(nodes,index(v));
        List<List<Node>> clist2 = remove(clist,index(v));
        
        //remove v from u's children list 
        Node u = parent(v);
        int ui = index(u);
        List<Node> uc = get(clist,ui);
        List<Node> uc2;
        for(int i=0; i<length(uc); i++) {
            if(!(get(uc,i) == v)) {
                uc2 = append(uc2,get(uc,i));
            }
        }
        
        clist2 = set(clist2,ui,uc2);
        
        
        Tree t2(rootNode,nodes2,clist2);
        return t2;
    }       

    String show2() const {
        String res = "[";
        for(int i=0; i<length(nodes); i++) {
            //out << get(tree.nodes, i) << ": " << get(tree.clist, i) << " . ";
            res += "(";             
            res += show(get(nodes, i));
            res += ",";             
            res += show(get(clist, i)); 
            res += ")";
        }
        res += "]";
        return res;
    }
    
    friend ostream& operator<<(ostream& out, const Tree& tree) {    out << tree.show2();
        return out;
    }    
    
    friend bool operator==(const Tree& lhs, const Tree& rhs) { 
        if(!setCompare(lhs.nodes,rhs.nodes)) {
            return false;            
        }
        for(int i=0; i<length(lhs.nodes); i++) {
            for(int j=0; j<length(lhs.nodes); j++) {
                if(get(lhs.nodes,i) == get(rhs.nodes,j)) {
                    if(!setCompare(get(lhs.clist,i),get(rhs.clist,j))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    friend bool operator!=(const Tree& lhs, const Tree& rhs) { return !(lhs == rhs); }
    
};

String show(Tree tree) { return tree.show2(); }

Tree newTree() {
    Tree t;
    return t;
}

Tree newTreeOwn(Node r) {
    Tree t(r);
    return t;
}

Node root(Tree t) { return t.root(); } //tested
Node parent(Tree t, Node v) { return t.parent(v); } //tested
Node lastNode(Tree t) { return t.lastNode(); } 
List<Node> children(Tree t, Node v) { return t.children(v); }
Int size(Tree t) { return t.size(); }
Bool isRoot(Tree t, Node v) { return t.isRoot(v); } //tested
Bool isLeaf(Tree t, Node v) { return t.isLeaf(v); }

Tree addOwnLeaf(Tree t, Node v, Node w) { return t.addOwnLeaf(v,w); }
Tree addLeaf(Tree t, Node v) { return t.addLeaf(v); }
Tree removeLeaf(Tree t, Node v) { return t.removeLeaf(v); }


/*
    CSM data type
*/
class CSMInstance {
	private:
    List<String> a;
    List<String> b;        
	   
	public:
    CSMInstance(List<String> constr_a, List<String> constr_b) : a(constr_a), b(constr_b) {        
    }	

    CSMInstance() : a(), b() { }
				
    //cardinality of a
    int coa() const {
        return a.size();
    }
    
    //cardinality of b
    int cob() const {
        return b.size();
    }
		
    //length of i-th element of a
    int lena(int i) const {
        return a[i].length();
    }
    
    //length of i-th element of b
    int lenb(int i) const {
        return b[i].length();
    }
    
    //substring call
    bool ssc(int ca, int cb, int oa, int ob, int l) const {
        for(int i=0; i<l; i++) {
            if(a[ca][oa+i] != b[cb][ob+i])
                return false;
        }
        return true;
    }
    
    String show2() const {
        String res = "(";
        res += show(a);
        res += ",";
        res += show(b);
        res += ")";
        return res;
    };
    
    friend ostream& operator<<(ostream& out, const CSMInstance& x) {
        out << x.show2();
        return out;
    }
};

int coa(CSMInstance x) { return x.coa(); }    
int cob(CSMInstance x) { return x.cob(); }    
int lena(CSMInstance x, int i) { return x.lena(i); }    
int lenb(CSMInstance x, int i) { return x.lenb(i); }
bool ssc(CSMInstance x, int ca, int cb, int oa, int ob, int l) { return x.ssc(ca,cb,oa,ob,l); }
String show(CSMInstance x) { return x.show2(); }

CSMInstance createCSM(List<String> a, List<String> b) { return CSMInstance(a,b); }

/*
    Misc functions
*/

//String to List<Char>
List<Char> s2lc(String x) {
    List<Char> res;    
    for(int i=0;i<length(x);i++) {
        res = append(res,get(x,i));
    }    
    return res;       
}

//List<Char> to String
String lc2s(List<Char> x) {
    String res;
    for(int i=0;i<length(x);i++) {
        res = append(res,get(x,i));
    }
    return res;
}

String show(List<Char> x) {
    return show(lc2s(x));
}

/*
    Tuples data type
*/
template < typename T1, typename T2 >
struct Tuple2 {
    T1 x1; T2 x2;
};

template < typename T1, typename T2 >
Tuple2< T1, T2 > tuple2(T1 v1, T2 v2) {
    Tuple2< T1, T2 > x;
    x.x1 = v1; x.x2 = v2;    
    return x;
}

template < typename T1, typename T2 >
String show(Tuple2< T1, T2 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + ")";
}

template < typename T1, typename T2 >
ostream& operator<<(ostream& out, const Tuple2< T1, T2 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << ")";     
    return out; 
}

template < typename T1, typename T2 >
bool operator==(const Tuple2< T1, T2 >& t1, const Tuple2< T1, T2 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 );
}

template < typename T1, typename T2 >
T1 get21(Tuple2< T1, T2 > t) {
    return t.x1;
}

template < typename T1, typename T2 >
T2 get22(Tuple2< T1, T2 > t) {
    return t.x2;
}

template < typename T1, typename T2 >
Tuple2< T1, T2 > set21(Tuple2< T1, T2 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2 >
Tuple2< T1, T2 > set22(Tuple2< T1, T2 > t, T2 v2) {
    t.x2 = v2; return t;
}


template < typename T1, typename T2, typename T3 >
struct Tuple3 {
    T1 x1; T2 x2; T3 x3;
};

template < typename T1, typename T2, typename T3 >
Tuple3< T1, T2, T3 > tuple3(T1 v1, T2 v2, T3 v3) {
    Tuple3< T1, T2, T3 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3;    
    return x;
}

template < typename T1, typename T2, typename T3 >
ostream& operator<<(ostream& out, const Tuple3< T1, T2, T3 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3 >
String show(Tuple3< T1, T2, T3 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + ")";
}

template < typename T1, typename T2, typename T3 >
bool operator==(const Tuple3< T1, T2, T3 >& t1, const Tuple3< T1, T2, T3 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 );
}

template < typename T1, typename T2, typename T3 >
T1 get31(Tuple3< T1, T2, T3 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3 >
T2 get32(Tuple3< T1, T2, T3 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3 >
T3 get33(Tuple3< T1, T2, T3 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3 >
Tuple3< T1, T2, T3 > set31(Tuple3< T1, T2, T3 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3 >
Tuple3< T1, T2, T3 > set32(Tuple3< T1, T2, T3 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3 >
Tuple3< T1, T2, T3 > set33(Tuple3< T1, T2, T3 > t, T3 v3) {
    t.x3 = v3; return t;
}


template < typename T1, typename T2, typename T3, typename T4 >
struct Tuple4 {
    T1 x1; T2 x2; T3 x3; T4 x4;
};

template < typename T1, typename T2, typename T3, typename T4 >
Tuple4< T1, T2, T3, T4 > tuple4(T1 v1, T2 v2, T3 v3, T4 v4) {
    Tuple4< T1, T2, T3, T4 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4 >
ostream& operator<<(ostream& out, const Tuple4< T1, T2, T3, T4 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4 >
String show(Tuple4< T1, T2, T3, T4 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + ")";
}

template < typename T1, typename T2, typename T3, typename T4 >
bool operator==(const Tuple4< T1, T2, T3, T4 >& t1, const Tuple4< T1, T2, T3, T4 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 );
}

template < typename T1, typename T2, typename T3, typename T4 >
T1 get41(Tuple4< T1, T2, T3, T4 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4 >
T2 get42(Tuple4< T1, T2, T3, T4 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4 >
T3 get43(Tuple4< T1, T2, T3, T4 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4 >
T4 get44(Tuple4< T1, T2, T3, T4 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4 >
Tuple4< T1, T2, T3, T4 > set41(Tuple4< T1, T2, T3, T4 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4 >
Tuple4< T1, T2, T3, T4 > set42(Tuple4< T1, T2, T3, T4 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4 >
Tuple4< T1, T2, T3, T4 > set43(Tuple4< T1, T2, T3, T4 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4 >
Tuple4< T1, T2, T3, T4 > set44(Tuple4< T1, T2, T3, T4 > t, T4 v4) {
    t.x4 = v4; return t;
}


template < typename T1, typename T2, typename T3, typename T4, typename T5 >
struct Tuple5 {
    T1 x1; T2 x2; T3 x3; T4 x4; T5 x5;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > tuple5(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5) {
    Tuple5< T1, T2, T3, T4, T5 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4; x.x5 = v5;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
ostream& operator<<(ostream& out, const Tuple5< T1, T2, T3, T4, T5 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << "," << show(t.x5) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
String show(Tuple5< T1, T2, T3, T4, T5 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + "," + show(t.x5) + ")";
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
bool operator==(const Tuple5< T1, T2, T3, T4, T5 >& t1, const Tuple5< T1, T2, T3, T4, T5 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 && t1.x5 == t2.x5 );
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
T1 get51(Tuple5< T1, T2, T3, T4, T5 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
T2 get52(Tuple5< T1, T2, T3, T4, T5 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
T3 get53(Tuple5< T1, T2, T3, T4, T5 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
T4 get54(Tuple5< T1, T2, T3, T4, T5 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
T5 get55(Tuple5< T1, T2, T3, T4, T5 > t) {
    return t.x5;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > set51(Tuple5< T1, T2, T3, T4, T5 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > set52(Tuple5< T1, T2, T3, T4, T5 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > set53(Tuple5< T1, T2, T3, T4, T5 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > set54(Tuple5< T1, T2, T3, T4, T5 > t, T4 v4) {
    t.x4 = v4; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5 >
Tuple5< T1, T2, T3, T4, T5 > set55(Tuple5< T1, T2, T3, T4, T5 > t, T5 v5) {
    t.x5 = v5; return t;
}


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
struct Tuple6 {
    T1 x1; T2 x2; T3 x3; T4 x4; T5 x5; T6 x6;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > tuple6(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) {
    Tuple6< T1, T2, T3, T4, T5, T6 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4; x.x5 = v5; x.x6 = v6;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
ostream& operator<<(ostream& out, const Tuple6< T1, T2, T3, T4, T5, T6 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << "," << show(t.x5) << "," << show(t.x6) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
String show(Tuple6< T1, T2, T3, T4, T5, T6 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + "," + show(t.x5) + "," + show(t.x6) + ")";
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
bool operator==(const Tuple6< T1, T2, T3, T4, T5, T6 >& t1, const Tuple6< T1, T2, T3, T4, T5, T6 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 && t1.x5 == t2.x5 && t1.x6 == t2.x6 );
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T1 get61(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T2 get62(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T3 get63(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T4 get64(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T5 get65(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x5;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
T6 get66(Tuple6< T1, T2, T3, T4, T5, T6 > t) {
    return t.x6;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set61(Tuple6< T1, T2, T3, T4, T5, T6 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set62(Tuple6< T1, T2, T3, T4, T5, T6 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set63(Tuple6< T1, T2, T3, T4, T5, T6 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set64(Tuple6< T1, T2, T3, T4, T5, T6 > t, T4 v4) {
    t.x4 = v4; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set65(Tuple6< T1, T2, T3, T4, T5, T6 > t, T5 v5) {
    t.x5 = v5; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
Tuple6< T1, T2, T3, T4, T5, T6 > set66(Tuple6< T1, T2, T3, T4, T5, T6 > t, T6 v6) {
    t.x6 = v6; return t;
}


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
struct Tuple7 {
    T1 x1; T2 x2; T3 x3; T4 x4; T5 x5; T6 x6; T7 x7;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > tuple7(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7) {
    Tuple7< T1, T2, T3, T4, T5, T6, T7 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4; x.x5 = v5; x.x6 = v6; x.x7 = v7;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
ostream& operator<<(ostream& out, const Tuple7< T1, T2, T3, T4, T5, T6, T7 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << "," << show(t.x5) << "," << show(t.x6) << "," << show(t.x7) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
String show(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + "," + show(t.x5) + "," + show(t.x6) + "," + show(t.x7) + ")";
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
bool operator==(const Tuple7< T1, T2, T3, T4, T5, T6, T7 >& t1, const Tuple7< T1, T2, T3, T4, T5, T6, T7 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 && t1.x5 == t2.x5 && t1.x6 == t2.x6 && t1.x7 == t2.x7 );
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T1 get71(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T2 get72(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T3 get73(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T4 get74(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T5 get75(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x5;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T6 get76(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x6;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
T7 get77(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t) {
    return t.x7;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set71(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set72(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set73(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set74(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T4 v4) {
    t.x4 = v4; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set75(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T5 v5) {
    t.x5 = v5; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set76(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T6 v6) {
    t.x6 = v6; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
Tuple7< T1, T2, T3, T4, T5, T6, T7 > set77(Tuple7< T1, T2, T3, T4, T5, T6, T7 > t, T7 v7) {
    t.x7 = v7; return t;
}


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
struct Tuple8 {
    T1 x1; T2 x2; T3 x3; T4 x4; T5 x5; T6 x6; T7 x7; T8 x8;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > tuple8(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8) {
    Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4; x.x5 = v5; x.x6 = v6; x.x7 = v7; x.x8 = v8;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
ostream& operator<<(ostream& out, const Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << "," << show(t.x5) << "," << show(t.x6) << "," << show(t.x7) << "," << show(t.x8) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
String show(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + "," + show(t.x5) + "," + show(t.x6) + "," + show(t.x7) + "," + show(t.x8) + ")";
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
bool operator==(const Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 >& t1, const Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 && t1.x5 == t2.x5 && t1.x6 == t2.x6 && t1.x7 == t2.x7 && t1.x8 == t2.x8 );
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T1 get81(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T2 get82(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T3 get83(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T4 get84(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T5 get85(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x5;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T6 get86(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x6;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T7 get87(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x7;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
T8 get88(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t) {
    return t.x8;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set81(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set82(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set83(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set84(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T4 v4) {
    t.x4 = v4; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set85(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T5 v5) {
    t.x5 = v5; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set86(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T6 v6) {
    t.x6 = v6; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set87(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T7 v7) {
    t.x7 = v7; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > set88(Tuple8< T1, T2, T3, T4, T5, T6, T7, T8 > t, T8 v8) {
    t.x8 = v8; return t;
}


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
struct Tuple9 {
    T1 x1; T2 x2; T3 x3; T4 x4; T5 x5; T6 x6; T7 x7; T8 x8; T9 x9;
};

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > tuple9(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6, T7 v7, T8 v8, T9 v9) {
    Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > x;
    x.x1 = v1; x.x2 = v2; x.x3 = v3; x.x4 = v4; x.x5 = v5; x.x6 = v6; x.x7 = v7; x.x8 = v8; x.x9 = v9;    
    return x;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
ostream& operator<<(ostream& out, const Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 >& t) { 
    out << "(" << show(t.x1) << "," << show(t.x2) << "," << show(t.x3) << "," << show(t.x4) << "," << show(t.x5) << "," << show(t.x6) << "," << show(t.x7) << "," << show(t.x8) << "," << show(t.x9) << ")";     
    return out; 
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
String show(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {    
    return "(" + show(t.x1) + "," + show(t.x2) + "," + show(t.x3) + "," + show(t.x4) + "," + show(t.x5) + "," + show(t.x6) + "," + show(t.x7) + "," + show(t.x8) + "," + show(t.x9) + ")";
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
bool operator==(const Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 >& t1, const Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 >& t2) {     
    return ( t1.x1 == t2.x1 && t1.x2 == t2.x2 && t1.x3 == t2.x3 && t1.x4 == t2.x4 && t1.x5 == t2.x5 && t1.x6 == t2.x6 && t1.x7 == t2.x7 && t1.x8 == t2.x8 && t1.x9 == t2.x9 );
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T1 get91(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x1;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T2 get92(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x2;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T3 get93(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x3;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T4 get94(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x4;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T5 get95(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x5;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T6 get96(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x6;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T7 get97(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x7;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T8 get98(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x8;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
T9 get99(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t) {
    return t.x9;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set91(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T1 v1) {
    t.x1 = v1; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set92(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T2 v2) {
    t.x2 = v2; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set93(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T3 v3) {
    t.x3 = v3; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set94(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T4 v4) {
    t.x4 = v4; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set95(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T5 v5) {
    t.x5 = v5; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set96(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T6 v6) {
    t.x6 = v6; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set97(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T7 v7) {
    t.x7 = v7; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set98(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T8 v8) {
    t.x8 = v8; return t;
}

template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > set99(Tuple9< T1, T2, T3, T4, T5, T6, T7, T8, T9 > t, T9 v9) {
    t.x9 = v9; return t;
}


/*
    Map data type
*/
template <typename T1, typename T2>
class Map {
    private:
    List<Tuple2<T1,T2>> data;
        
    public:
    Map(List<Tuple2<T1,T2>> constr_data) : data(constr_data) {
    }
    
    Map() : data({}) {  }
    
    Bool isMap() const {        
        for(int i=0;i<length(data);i++) {
            for(int j=0;j<length(data);j++) {
                if(i!=j) {
                    T1 x1 = get21<T1,T2>(get(data,i));
                    T1 x2 = get21<T1,T2>(get(data,j));
                    if(x1 == x2) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    Bool isDefined(T1 x) const {
        for(int i=0;i<length(data);i++) {
            if(x == get21<T1,T2>(get(data,i))) {
                return true;
            }
        }
        return false;
    }
    
    T2 imageOf(T1 x) const {
        for(int i=0;i<length(data);i++) {
            if(x == get21<T1,T2>(get(data,i))) {
                return get22<T1,T2>(get(data,i));
            }
        }        
        panic("imageOf called for undefined element: "+show(x));
        throw logic_error("imageOf called for undefined element");
    }  

    List<T1> inverseOf(T2 y) const {
        List<T1> res;
        for(int i=0;i<length(data);i++) {
            if(y == get22<T1,T2>(get(data,i))) {                
                res = append(res,get21<T1,T2>(get(data,i)));
            }
        }        
        return res;
    } 
    
    Map<T1,T2> undefine(T1 x) const {
        List<Tuple2<T1,T2>> data2;        
        for(int i=0;i<length(data);i++) {
            if(x != get21<T1,T2>(get(data,i))) {                
                data2 = append(data2,get(data,i));
            }
        }        
        return Map<T1,T2>(data2);
    }   
        
    Map<T1,T2> setImage(T1 x, T2 y) const {
        Tuple2<T1,T2> z = tuple2<T1,T2>(x,y);
        List<Tuple2<T1,T2>> data2;   
        Bool found = false;        
        for(int i=0;i<length(data);i++) {
            if(x == get21<T1,T2>(get(data,i))) {                
                found = true;
                data2 = append(data2,z);
            } else {
                data2 = append(data2,get(data,i));
            }
        }

        if(!found) {
            data2 = append(data2,z);
        }
        return Map<T1,T2>(data2);
    }   

    List<T1> domainOf() const {
        List<T1> res;    
        for(int i=0;i<length(data);i++) {
            res = append(res,get21<T1,T2>(get(data,i)));
        }
        return res;
    }
     
    String show2() const {
        return show(data);
    }
     
    friend ostream& operator<<(ostream& out, const Map<T1,T2>& x) {
        out << x.show2();
        return out;
    }    

    
    friend bool operator==(const Map<T1,T2>& m1, const Map<T1,T2>& m2) {
        if(length(m1.data) != length(m2.data)) {
            return false;
        }
        
        T1 x;
        for(int i=0;i<length(m1.data);i++) {
            x = get21<T1,T2>(get(m1.data,i));
            if(!m2.isDefined(x) || m1.imageOf(x) != m2.imageOf(x)) {
                return false;
            }                
        }
        return true;
    }
    
    friend bool operator!=(const Map<T1,T2>& m1, const Map<T1,T2>& m2) {
        return !(m1 == m2);
    }
    
};

template <typename T1, typename T2>
String show(Map<T1,T2> x) { return x.show2(); };

template <typename T1, typename T2>
Map<T1,T2> emptyMap() { return Map<T1,T2>(); };

template <typename T1, typename T2>
Bool isMap(Map<T1,T2> m) { return m.isMap(); };

template <typename T1, typename T2>
Bool isDefined(Map<T1,T2> m, T1 x) { return m.isDefined(x); };

template <typename T1, typename T2>
T2 imageOf(Map<T1,T2> m, T1 x) { return m.imageOf(x); };

template <typename T1, typename T2>
List<T1> inverseOf(Map<T1,T2> m, T2 y) { return m.inverseOf(y); };

template <typename T1, typename T2>
Map<T1,T2> undefine(Map<T1,T2> m, T1 x) { return m.undefine(x); };

template <typename T1, typename T2>
Map<T1,T2> setImage(Map<T1,T2> m, T1 x, T2 y) { return m.setImage(x,y); };

template <typename T1, typename T2>
List<T1> domainOf(Map<T1,T2> m) { return m.domainOf(); };

template <typename T1, typename T2>
Map<T1,T2> joinMaps(Map<T1,T2> m1, Map<T1,T2> m2) { 
    List<T1> dom1 = domainOf(m1);
    List<T1> dom2 = domainOf(m2);
    T1 x;
    for(int i=0; i<length(dom2); i++) {
        x = get(dom2,i);
        if(contains(dom1,x)) {
            panic(("joinMaps: x = '"+show(x)+"' is defined in both maps"));
        }
        m1 = setImage(m1,x,imageOf(m2,x));
    }
    return m1;    
};
