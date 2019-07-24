bool isIsomorph(Tree t1, Tree t2) {
    if(isLeaf(t1, root(t1)) && isLeaf(t2, root(t2))) {
        return true;
    }
    
    if (length(children(t1, root(t1))) == length(children(t2, root(t2)))) {
        int len = length(children(t1, root(t1)));
        for (int i = 0; i < len; i++) {
            return isIsomorph(subtree(t1, get(children(t1, root(t1)), i)), subtree(t2, get(children(t2, root(t2)), i)));
        }
    }
    
    return false;
}

Map<Node, Node> mapIsomorph(Tree t1, Tree t2, Map<Node, Node> map) {
    map = setImage(map, root(t1), root(t2));
    int len = length(children(t1, root(t1)));
    
    for (int i = 0; i < len; i++) {
        Node curr1 = get(children(t1, root(t1)), i);
        Node curr2 = get(children(t2, root(t2)), i);

        map = mapIsomorph(subtree(t1, curr1), subtree(t2, curr2), map);
    }
    
    return map;
}

Map<Node, Node> isomorphism(Tree t1, Tree t2) {
    Map<Node, Node> map = emptyMap<Node, Node>();
    
    if(isIsomorph(t1, t2)) {
        return mapIsomorph(t1,t2, map);
    }
    
    return emptyMap<Node, Node>();
        
}
