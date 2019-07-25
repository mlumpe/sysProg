#pragma once

#include "Mod_sizeLogspace.cpp"
#include "Mod_firstChild.cpp"

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

int countNumber(Tree t, Node root, int number){
	int cnt = 0;
	Node n = firstChild(t, root);
	int size = sizeLogspace(t, n);
	if(size == number){
		cnt++;
	}
	
	while(hasNextSibling(t, n)){
		n = nextSibling(t, n);
		size = sizeLogspace(t, n);
		if(size == number){
			cnt++;
		}
	}
	
	return cnt;
}

bool lexikoLess(Tree t1, Tree t2, Node n1, Node n2, int numChildren){
	int act = 0;
	while(numChildren != 0){
		int c1 = countNumber(t1, n1, act);
		int c2 = countNumber(t2, n2, act);
		if(c1>c2)
			return true;
		else if(c1<c2)
			return false;
		else{
			numChildren -= c1;
			act++;
		}
	}
	return false;
}

bool nonRecursiveCheck(Tree t1, Tree t2, Node n1, Node n2){
	int s1 = sizeLogspace(t1, n1);
	int s2 = sizeLogspace(t2, n2);
	int num1 = numChildren(t1, n1);
	int num2 = numChildren(t2, n2);
	if( s1 < s2)
		return true;
	if(s1 == s2 && num1 < num2)
		return true;
	if(s1 == s2 && num1 == num2 && lexikoLess(t1, t2, n1, n2, num1))
		return true;
	
	return false;
}	  
	  