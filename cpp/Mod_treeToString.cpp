#pragma once

#include "Mod_subtree.cpp"

String treeToStringHelper(Tree tree, int d){
	Node act = root(tree);
	String res;
	for (int i = 0; i<d*3; i++){
		res += " ";
	}
	res += show(act);
    res += "\n";
	for(int i = 0; i<length(children(tree, act));i++){
		res += treeToStringHelper(subtree(tree, get(children(tree,act), i)), d+1);
	}
	return res;
}

String treeToString(Tree tree){
	return treeToStringHelper(tree, 0);							 
}
