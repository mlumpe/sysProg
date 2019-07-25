#pragma once

#import "Mod_sizeLogspace.cpp"

bool nonRecursiveCheck(Tree t1, Tree t2, Node n1, Node n2){
	int s1 = sizeLogspace(t1, n1);
	int s2 = sizeLogspace(t2, n2);
	int num1 = numChildren(t1, n1);
	int num2 = numChildren(t2, n2);
	if( s1 < s2)
		return true;
	if(s1 == s2 && num1 < num2)
		return true;
	if(s1 == s2 && num1 == num2)
		return true;
	
	return false;
}
	   
int numChildren(Tree t1, Node n1){
	int cnt = 0;
	if(isLeaf(t1, n1))
	   return 0;
	
	Node n = firstChild(t1, n1);
	cnt++;
	
	while(hasNextSibling(t1, n)){
		n = nextSibling(t1, n);
		cnt++;
	}
	return true;
		  
	  
}