Node nextSibling(Tree t, Node v) {
    Node res = createNode(-1);
    int cnt = 0;
    Node curr;
    List<Node> ln = children(t, parent(t,v));
    
    while (length(ln) == 1) {
        curr parent(t, v);
        cnt++;
    }
    
    return res;
}
