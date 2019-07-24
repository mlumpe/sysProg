Tree removeSubtree_h(Tree t, Node v) {
    List<Node> lst = children(t,v);
    for (int i = 0; i < length(lst); i++) {
        Node curr = get(lst, i);
        if(isLeaf(t, curr)) {
            t = removeLeaf(t, curr);
        } else {
            t = removeSubtree_h(t,curr);
            t = removeSubtree_h(t,v);
        }
    }
    
    return t;
}

Tree removeSubtree(Tree t, Node v) {
    if (isLeaf(t,v)) {
        return t;
    } else {
        return removeSubtree_h(t, v);
    }
}
