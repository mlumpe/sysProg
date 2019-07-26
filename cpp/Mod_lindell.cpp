#pragma once

#include "Mod_firstChild.cpp"
#include "Mod_hasNextSibling.cpp"
#include "Mod_nextSibling.cpp"
#include "Mod_nonRecursiveCheck.cpp"
#include "Mod_sizeLogspace.cpp"

Tuple2<bool, Node> kBlockSize(Tree t, Node v, int minimum = 0) {
    Node kid = firstChild(t,v);
    Node resKid = kid;
    int res = sizeLogspace(t, v); //initialwert, da größer als alle k's
    
    bool found= false;
    
    while (true) {
        int kidSize = sizeLogspace(t, kid);
        
        if (kidSize > minimum) {
            if(kidSize < res){
                found = true;
                res = kidSize;
                resKid = kid;
            }
        }
        
        if (hasNextSibling(t,kid)) {
            kid = nextSibling(t, kid);
        } else {
            break;
        }
    }
    
    return tuple2(found, resKid);
}

int lindell(Tree s, Tree t) {
    cout << "u;v;k;res" << endl;
    int res = 0;
    int k = 0;
    Node ku;
    Node kv;
    bool nextPossible;
    
    Node actU = root(s);
    Node actV = root(t);
    while(true){
        cout << actU << ";" << actV << ";" << k << ";"<< res << endl;
        if(res == 0){
            if(nonRecursiveCheck(s,t,actU, actV)) {
                // nicht isomorph; s[u] < t[v]
                res = -1;
            } else if(nonRecursiveCheck(t,s,actV, actU)) {
                //nicht isomorph; s[u] < t[v]
                res = 1;
            } else {
                if(isLeaf(s,actU) && isLeaf(t, actV)){
                    res = 0;
                    nextPossible = false;
                }else{
                    nextPossible = get21(kBlockSize(s, actU, k));
                    ku = get22(kBlockSize(s, actU, k));
                    kv = get22(kBlockSize(t, actV, k));
                }
                if(!nextPossible){
                    if(isRoot(s, actU))
                        return res;
                    k = sizeLogspace(s, actU);
                    actU = parent(s, actU);
                    actV = parent(t, actV);
                }else{
                    actU = ku;
                    actV = kv;
                    k = 0;
                }
            }
        }else{
            if(isRoot(s, actU))
                return res;
            k = sizeLogspace(s, actU);
            actU = parent(s, actU);
            actV = parent(t, actV);
        }

    }
    return res;
}
