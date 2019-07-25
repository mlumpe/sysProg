#pragma once

#include "Mod_nextSibling.cpp"

bool hasNextSibling(Tree t, Node v) {
    Node n;
    try {
        n = nextSibling(t,v);
    } catch (exception& e) {
        return false;
    }
    
    if(sp_eq(n, (createNode(-1)))) return false;
    return true;
}
