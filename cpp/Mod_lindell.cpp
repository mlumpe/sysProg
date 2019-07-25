#pragma once

#include "Mod_firstChild.cpp"
#include "Mod_hasNextSibling.cpp"
#include "Mod_nextSibling.cpp"
#include "Mod_nonRecursiveCheck.cpp"
#include "Mod_sizeLogspace.cpp"




int lindell(Tree s, Tree t) {
    int res = 0;
    
    if(nonRecursiveCheck(s,t,root(s), root(t))) {
        // nicht isomorph; s[u] < t[v]
        return -1;
    } else if(nonRecursiveCheck(t,s,root(t), root(s))) {
        //nicht isomorph; s[u] < t[v]
        return 1;
    } else {
        Node vs = firstChild(s, root(s));
        Node vt = firstChild(t, root(t));
        bool isIsomorph = false;
        
        while (hasNextSibling(s, vs)) {
            while (hasNextSibling(t, vt)) {
                bool hasIsmorphSubtree = false;
                if(sizeLogspace(s, vs) == sizeLogspace(t, vt)) {
                    if(nonRecursiveCheck(s,t,vs,vt)) {
                        res = -1; // s[u] < t[v]
                    }
                    
                    if(nonRecursiveCheck(t,s,vt,vs)) {
                        res = 1; //t[v] < s[u]
                    }
                }
                vt = nextSibling(t, vt);
            }
            vs = nextSibling(s, vs);
        }
        
        return res;
    }
}
