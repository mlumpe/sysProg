#pragma once


Node firstChild(Tree t, Node n);
Node firstChild_debug(Tree t, Node n);

class firstChild_class {
    
    //VARIABLES
    Tree t;
    Tree t_spnew;
    Node n;
    Node n_spnew;
    Node res;
    Node res_spnew;
    bool debug_spv;
    
    //PREDICATES
    
    
    //OPERATIONS
    void o_init() {
        res_spnew = first(children(t, n));
        
        res = res_spnew;
        
        if(debug_spv) {
            cout << "o_init" << " ; "
            << "" << ";"  << "" << ";"  << res
            << endl;
        }
        
        return;
    }
    
public:
    firstChild_class(Tree constr_t, Node constr_n) : t(constr_t), n(constr_n)   {  }
    
    Node execute(bool debug) {
        debug_spv = debug;
        
        if(debug_spv) {
            cout << "firstChild" << ";"
            << "t"<< "; " << "n"<< "; " << "res"
            << endl;
            
            cout << "" << "; "
            << t << ";"  << n << ";"  << ""
            << endl;
        }
        
        o_init();
        return res;
    }
    
    
};

Node firstChild(Tree t, Node n) {
    firstChild_class obj(t, n);
    return obj.execute(false);
}


Node firstChild_debug(Tree t, Node n) {
    firstChild_class obj(t, n);
    return obj.execute(true);
}
