#pragma once

#include "Mod_subtree.cpp"

int depth(Tree t) {
    int len = length(children(t, root(t)));
    int maximum = 0;
    
    for (int i = 0; i < len; i++) {
        Node curr = get(children(t, root(t)), i);
        
        maximum = max(maximum, depth(subtree(t, curr))+1);
    }
    
    return maximum;
}
