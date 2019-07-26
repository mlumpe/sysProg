#pragma once

#include "Mod_subtree.cpp"
#include "Mod_eval.cpp"

bool isVariable(String s) {
    List<Char> lst = s2lc(s);
    bool variable = false;
    char firstChar = first(lst);
    
    if (firstChar >= 'a' && firstChar <= 'z') {
        variable = true;
    }
    
    lst = removeFirst(lst);
    
    for (int i = 0; i < length(lst) ; i++) {
        Char c = get(lst, i);
        if(!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
            variable = false;
        }
    }
    
    return variable;
}

List<Node> getVariablesPos(Map<Node, String> map) {
    List<Node> variables = {};
    
    for (Node n: domainOf(map)) {
        if(isVariable(imageOf(map, n))) {
            variables = append(variables, n);
        }
    }
    
    return variables;
}

bool satisfiable(Tuple2<Tree, Map<Node, String>> f) {
    Map<Node, String> map = get22(f);
    List<Node> variables = getVariablesPos(map);
    
    if(empty(variables)) {
        Tuple2<Tree, Map<Node, String>> t = eval(f);
        Map<Node, String> resMap = get22(t);
        Tree resTree = get21(t);
        
        return imageOf(resMap, root(resTree)) == "TRUE" ? true : false;
    } else {
        String strue = "TRUE";
        String sflase = "FALSE";
        Map<Node, String> map1 = setImage(map, first(variables), strue);
        Map<Node, String> map2 = setImage(map, first(variables), sflase);
        
        bool b1 = satisfiable(set22(f, map1));
        bool b2 = satisfiable(set22(f, map2));

        cout << imageOf(map, first(variables)) << ";" << b1 << ";" << b2 << ";" << endl;
        
        return satisfiable(set22(f, map1)) || satisfiable(set22(f, map2));
    }
}
