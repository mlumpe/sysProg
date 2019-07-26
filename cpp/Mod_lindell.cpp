#pragma once

#include "Mod_firstChild.cpp"
#include "Mod_hasNextSibling.cpp"
#include "Mod_nextSibling.cpp"
#include "Mod_nonRecursiveCheck.cpp"
#include "Mod_sizeLogspace.cpp"

int kBlockSize(Tree t, Node v, int minimum = 0) {
    Node kid = firstChild(t,v);
    int res = sizeLogspace(t, v); //initialwert, da größer als alle k's
    
    while (true) {
        int kidSize = sizeLogspace(t, kid);
        
        //cout << "kidSize: " << kidSize << endl;
        
        if (kidSize > minimum) {
            res = min(res, kidSize);
            //cout << "res : " << res << endl;
        }
        
        if (hasNextSibling(t,kid)) {
            kid = nextSibling(t, kid);
        } else {
            break;
        }
    }
    
    return res;
}

int lindell(Tree s, Tree t) {
    int res = 0;
    int ku = 0;
    int kv = 0;
    
    if(nonRecursiveCheck(s,t,root(s), root(t))) {
        // nicht isomorph; s[u] < t[v]
        return -1;
    } else if(nonRecursiveCheck(t,s,root(t), root(s))) {
        //nicht isomorph; s[u] < t[v]
        return 1;
    } else {
        Node u = root(s);
        Node v = root(t);

        while (true) {
            ku = kBlockSize(s, u, ku);
            cout << "ku: " << ku << endl;
            while (true) {
                int kv = kBlockSize(t,v, kv);
                if (kv == ku) {
                    if(nonRecursiveCheck(s,t,u,v)) {
                        res = -1;
                    }
                    cout << u << ";" << v << ";" << ku << ";" << res << ";" << endl;
                }
                
                //Abbruchbedingung
                if (hasNextSibling(t,v)) {
                    v = nextSibling(t, v);
                } else {
                    break;
                }
            }
            
            //Abbruchbedingung
            if (hasNextSibling(s,u)) {
                u = nextSibling(s, u);
            } else {
                break;
            }
        }
        
        return res;
    }
}
