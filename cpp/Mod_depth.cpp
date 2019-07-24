int depthChilds(Tree t, int i, int j, int max) {
    if(j == children(t, root(t))) {
        return max;
    } else {
        depthChilds(t, i, (j+1), sp_max(depthHelper(subtree(t, get(children(t, root(t)), j)), i)));
    }
}

int depthHelper(Tree t, int i) {
    if(isLeaf(t, root(t))) {
        return i;
    } else {
        return depthChilds(t, (i+1), 0, 0);
    }
}

int depth(Tree t) {
    if (isLeaf(t, root(t))) {
        return 0;
    } else {
        
    }
}
