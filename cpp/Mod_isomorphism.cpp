#pragma once

bool isIsomorph(Tree t1, Tree t2) {
    if(isLeaf(t1, root(t1)) && isLeaf(t2, root(t2))) {
        return true;
    }
    
    if (length(children(t1, root(t1))) == length(children(t2, root(t2)))) {
        List<Node> toMatch1 = children(t1, root(t1));
        List<Node> toMatch2 = children(t2, root(t2));
        
        int cnt = 0;
        while(!empty(toMatch1)){
            Node n1 = first(toMatch1);
            Node n2 = first(toMatch2);
            if(cnt > length(toMatch2)){
                return false;
            }
            
            if(isIsomorph(subtree(t1, n1), subtree(t2, n2))){
                toMatch1 = removeFirst(toMatch1);
                toMatch2 = removeFirst(toMatch2);
                cnt = 0;
            }else{
                toMatch2 = append(removeFirst(toMatch2), first(toMatch2));
                cnt++;
            }
        }
        return true;
    }else{
        return false;
    }
}

Map<Node, Node> mapIsomorph(Tree t1, Tree t2, Map<Node, Node> map) {
    map = setImage(map, root(t1), root(t2));
    
    List<Node> toMatch1 = children(t1, root(t1));
    List<Node> toMatch2 = children(t2, root(t2));
        
    while(!empty(toMatch1)){
        Node n1 = first(toMatch1);
        Node n2 = first(toMatch2);
        
        if(isIsomorph(subtree(t1, n1), subtree(t2, n2))){
           toMatch1 = removeFirst(toMatch1);
           toMatch2 = removeFirst(toMatch2);
           map = mapIsomorph(subtree(t1, n1), subtree(t2, n2), map);
        }else{
            toMatch2 = append(removeFirst(toMatch2), first(toMatch2));
        }
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
