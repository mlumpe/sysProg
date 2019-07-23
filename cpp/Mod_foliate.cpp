#pragma once

function<Int(Int)> foliate_h(Int k) {
    return [k](Int i) { return k + i; };
}

List2Int foliate(ListInt inp);
List2Int foliate_debug(ListInt inp);

class foliate_class {
    
    //VARIABLES        
    ListInt inp;
    ListInt inp_spnew;
    Int cur;
    Int cur_spnew;
    Int lastMax;
    Int lastMax_spnew;
    List2Int res;
    List2Int res_spnew;
    bool debug_spv;
    
    //PREDICATES
    bool p_empty() {
        return empty(inp);
    }

    //OPERATIONS
    void o_init() {                    
        res_spnew = {};
        lastMax_spnew = 0;
        
        res = res_spnew;
        lastMax = lastMax_spnew;       

        if(debug_spv) {
            cout << "o_init" << " ; "  
             << "" << ";"  << "" << ";"  << lastMax << ";"  << res  
            << endl;   
        }

        if(p_empty()) {
            o_end();
        } else {
            o_next();
        }
    }

    void o_next() {                    
        cur_spnew = first(inp);
        inp_spnew = removeFirst(inp);
        res_spnew = append(res, map<Int,Int>(foliate_h(lastMax), firstNNumbers(cur_spnew)));
        lastMax_spnew = reduce<Int>(sp_max, last(res_spnew));
        
        cur = cur_spnew;
        inp = inp_spnew;
        res = res_spnew;
        lastMax = lastMax_spnew;       

        if(debug_spv) {
            cout << "o_next" << " ; "  
             << inp << ";"  << cur << ";"  << lastMax << ";"  << res  
            << endl;   
        }

        if(p_empty()) {
            o_end();
        } else {
            o_next();
        }
    }

    void o_end() {                                  
        if(debug_spv) {
            cout << "o_end" << " ; "  
             << "" << ";"  << "" << ";"  << "" << ";"  << ""  
            << endl;   
        }

        return;
    }
    
    public:
    foliate_class(ListInt constr_inp) : inp(constr_inp)   {  }
        
    List2Int execute(bool debug) {           
        debug_spv = debug;
        
        if(debug_spv) {
            cout << "foliate" << ";"  
            << "inp"<< "; " << "cur"<< "; " << "lastMax"<< "; " << "res" 
            << endl;             
            
            cout << "" << "; "  
             << inp << ";"  << "" << ";"  << "" << ";"  << ""  
            << endl;   
        }
        
        o_init();           
        return res;
    }
        
    
};

List2Int foliate(ListInt inp) {
    foliate_class obj(inp);  
    return obj.execute(true);
}


List2Int foliate_debug(ListInt inp) {
    foliate_class obj(inp);  
    return obj.execute(true);
}

/*
 Aufgabe 1
    1.) Die Funktion berechnet für jeden Werte der List eine  Subliste mit dem jeweiligen Wert als Länge. Der Inhalt sind natürliche Zahlen, die inkrementiert werden für die gesamte Liste.
 
        Beispiel: [4,1,2,3]
 
        1   5   6   8
        2       7   9
        3           10
        4
    2.) - grundlegende Funktionen
        - Variablennamen
    3.) - Signaturen (z.B. o_init)
        - Data_foliate wurde in Haskell erstellt
        - Implementierung der Kontrollstruktur (Schleifen, Bedingungen)
        - C++ lokale Variablen; Haskell nur Parameter
        - Debug
    4.) C++
        - Zeigt Schritt für Schritt die Funktionen und Parameter (Trace)
            - Es wird inp, cur, lastMax und res ausgegeben
                - inp ... Eingabe
                - cur ... Aktueller Parameter der Eingabe
                - lastMax ... Zählervariable
                - res ... Ausgabe
        Haskell
        - Zeigt Schritt für Schritt nur die aufgerufenen Funktionen
 */
