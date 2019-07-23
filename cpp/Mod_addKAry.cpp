#pragma once


ListInt addKAry(Int base, ListInt list1, ListInt list2);
ListInt addKAry_debug(Int base, ListInt list1, ListInt list2);

class addKAry_class {
    
    //VARIABLES        
    Int base;
    Int base_spnew;
    ListInt list1;
    ListInt list1_spnew;
    ListInt list2;
    ListInt list2_spnew;
    Int carry;
    Int carry_spnew;
    Int sum;
    Int sum_spnew;
    ListInt res;
    ListInt res_spnew;
    bool debug_spv;
    
    //PREDICATES
    bool l1_empty() {
        return empty(list1);
    }

    bool l2_empty() {
        return empty(list2);
    }

    bool or_empty() {
        return sp_or(empty(list1), empty(list2));
    }

    bool and_empty() {
        return sp_and(empty(list1), empty(list2));
    }

    bool carry_set() {
        return sp_eq(carry, 1);
    }

    //OPERATIONS
    void o_init() {                    
        res_spnew = {};
        carry_spnew = 0;
        
        res = res_spnew;
        carry = carry_spnew;       

        if(debug_spv) {
            cout << "o_init" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << carry << ";"  << "" << ";"  << res  
            << endl;   
        }

        if(and_empty()) {
            o_end();
        } else {
            o_calc();
        }
    }

    void o_next() {                    
        carry_spnew = sp_div(sum, base);
        res_spnew = prepend(res, sp_mod(sum, base));
        list1_spnew = removeLast(list1);
        list2_spnew = removeLast(list2);
        
        carry = carry_spnew;
        res = res_spnew;
        list1 = list1_spnew;
        list2 = list2_spnew;       

        if(debug_spv) {
            cout << "o_next" << " ; "  
             << "" << ";"  << list1 << ";"  << list2 << ";"  << carry << ";"  << "" << ";"  << res  
            << endl;   
        }

        o_calc();
    }

    void o_l1add() {                    
        carry_spnew = sp_div(sum, base);
        sum_spnew = sp_mod(sum, base);
        res_spnew = prepend(res, sum);
        list1_spnew = removeLast(list1);
        
        carry = carry_spnew;
        sum = sum_spnew;
        res = res_spnew;
        list1 = list1_spnew;       

        if(debug_spv) {
            cout << "o_l1add" << " ; "  
             << "" << ";"  << list1 << ";"  << "" << ";"  << carry << ";"  << sum << ";"  << res  
            << endl;   
        }

        if(l1_empty()) {
            if(carry_set()) {
                o_carry();
            } else {
                o_end();
            }
        } else {
            o_calc();
        }
    }

    void o_l2add() {                    
        carry_spnew = sp_div(sum, base);
        sum_spnew = sp_mod(sum, base);
        res_spnew = prepend(res, sum);
        list2_spnew = removeLast(list2);
        
        carry = carry_spnew;
        sum = sum_spnew;
        res = res_spnew;
        list2 = list2_spnew;       

        if(debug_spv) {
            cout << "o_l2add" << " ; "  
             << "" << ";"  << "" << ";"  << list2 << ";"  << carry << ";"  << sum << ";"  << res  
            << endl;   
        }

        if(l2_empty()) {
            if(carry_set()) {
                o_carry();
            } else {
                o_end();
            }
        } else {
            o_calc();
        }
    }

    void o_carry() {                    
        res_spnew = prepend(res, 1);
        
        res = res_spnew;       

        if(debug_spv) {
            cout << "o_carry" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << res  
            << endl;   
        }

        o_end();
    }

    void o_end() {                    

        
       

        if(debug_spv) {
            cout << "o_end" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << ""  
            << endl;   
        }

        return;
    }

    void o_calc() {                    

        
       

        if(debug_spv) {
            cout << "o_calc" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << ""  
            << endl;   
        }

        if(or_empty()) {
            if(l1_empty()) {
                o_calc_l2();
            } else {
                o_calc_l1();
            }
        } else {
            o_calc_both();
        }
    }

    void o_calc_both() {                    
        sum_spnew = sp_add(last(list1), sp_add(last(list2), carry));
        
        sum = sum_spnew;       

        if(debug_spv) {
            cout << "o_calc_both" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << sum << ";"  << ""  
            << endl;   
        }

        o_next();
    }

    void o_calc_l1() {                    
        sum_spnew = sp_add(last(list1), carry);
        
        sum = sum_spnew;       

        if(debug_spv) {
            cout << "o_calc_l1" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << sum << ";"  << ""  
            << endl;   
        }

        o_l1add();
    }

    void o_calc_l2() {                    
        sum_spnew = sp_add(last(list2), carry);
        
        sum = sum_spnew;       

        if(debug_spv) {
            cout << "o_calc_l2" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << "" << ";"  << sum << ";"  << ""  
            << endl;   
        }

        o_l2add();
    }
    
    public:
    addKAry_class(Int constr_base, ListInt constr_list1, ListInt constr_list2) : base(constr_base), list1(constr_list1), list2(constr_list2)   {  }
        
    ListInt execute(bool debug) {           
        debug_spv = debug;
        
        if(debug_spv) {
            cout << "addKAry" << ";"  
            << "base"<< "; " << "list1"<< "; " << "list2"<< "; " << "carry"<< "; " << "sum"<< "; " << "res" 
            << endl;             
            
            cout << "" << "; "  
             << base << ";"  << list1 << ";"  << list2 << ";"  << "" << ";"  << "" << ";"  << ""  
            << endl;   
        }
        
        o_init();           
        return res;
    }
        
    
};

ListInt addKAry(Int base, ListInt list1, ListInt list2) {
    addKAry_class obj(base, list1, list2);  
    return obj.execute(false);
}


ListInt addKAry_debug(Int base, ListInt list1, ListInt list2) {
    addKAry_class obj(base, list1, list2);  
    return obj.execute(true);
}