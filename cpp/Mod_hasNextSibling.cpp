#pragma once

bool hasNextSibling(Tree t, Node v) {
    if(isRoot(t, v)) return false;
    
    List<Node> sibling = children(t,parent(t,v));
    int i = 0;
    
    while(!(get(sibling, i) == v)) {
        i++;
    }
    
    if(length(sibling) > i+1) {
        return true;
    } else {
        return false;
    }
}
