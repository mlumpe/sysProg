//int absolute(int a) {return a < 0 ? -a : a;}

#pragma once


Int absolute(Int a);
Int absolute_debug(Int a);

class absolute_class {
    
    //VARIABLES        
    Int a;
    Int a_spnew;
    Int res;
    Int res_spnew;
    bool debug_spv;
    
    //PREDICATES


    //OPERATIONS
    void o_init() {                    
        res_spnew = sp_if(sp_lt(a, 0), sp_minus(0, a), a);
        
        res = res_spnew;       

        if(debug_spv) {
            cout << "o_init" << " ; "  
             << "" << ";"  << res  
            << endl;   
        }

        return;
    }
    
    public:
    absolute_class(Int constr_a) : a(constr_a)   {  }
        
    Int execute(bool debug) {           
        debug_spv = debug;
        
        if(debug_spv) {
            cout << "absolute" << ";"  
            << "a"<< "; " << "res" 
            << endl;             
            
            cout << "" << "; "  
             << a << ";"  << ""  
            << endl;   
        }
        
        o_init();           
        return res;
    }
        
    
};

Int absolute(Int a) {
    absolute_class obj(a);  
    return obj.execute(false);
}


Int absolute_debug(Int a) {
    absolute_class obj(a);  
    return obj.execute(true);
}