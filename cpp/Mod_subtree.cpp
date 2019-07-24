#pragma once

Tree addChildren(Tree orig, Tree newTree, Node node){
	for(int i = 0; i<length(children(orig, node));i++){
		newTree = addOwnLeaf(newTree, node, get(children(orig, node), i));	
		newTree = addChildren(orig, newTree, get(children(orig, node), i));
	}
	
	return newTree;
}

Tree subtree(Tree tree, Node node){
	Tree newTree = newTreeOwn(node);
	newTree = addChildren(tree, newTree, node);
	return newTree;
}
