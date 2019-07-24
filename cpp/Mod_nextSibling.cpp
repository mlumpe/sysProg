int findIndex(Tree t, Node n, int i) {
    List<Node> childs = children(t, parent(t,n));
    if(get(childs,i) == n) {
        return i;
    } else {
        return findIndex(t,n,(i+1));
    }
}

Node nextSibling(Tree t, Node v) {
    if(isRoot(t,v)) {
        return createNode(-1);
    } else {
        List<Node> siblings = children(t, parent(t,v));
        return get(siblings, findIndex(t,v,0)+1);
    }
}
