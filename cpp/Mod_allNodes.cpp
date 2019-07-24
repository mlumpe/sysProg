List<Node> helper(Tree t, Node v, List<Node> res) {
    if(isLeaf(t,v)) {
        return res;
    } else {
        for (int i = 0; i < length(children(t,v)); i++) {
            res = append(helper(t, get(children(t,v), i), res), get(children(t,v), i));
        }
        return res;
    }
}

List<Node> allNodes(Tree t) {
    if (isLeaf(t, root(t))) {
        return {root(t)};
    } else {
        return append(helper(t, root(t), {}), root(t));
    }
}
