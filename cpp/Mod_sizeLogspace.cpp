#pragma once

#include "Mod_firstChild.cpp"
#include "Mod_hasNextSibling.cpp"
#include "Mod_nextSibling.cpp"

int sizeLogspace_debug(Tree t, Node n){
	cout << "action;node;count" << endl;
	Node start = n;
	int last = 0; //0-down, 1-over, 2-up
	int cnt = 1;
	if(isLeaf(t, n)){
		return cnt;
	}
	cout << "down;" << n << ";" << cnt << endl;
	n = firstChild(t, n);
	cnt++;
	
	while(true){
		if(last == 0 || last == 1){
			if(!isLeaf(t, n)){
				cout << "down;" << n << ";" << cnt << endl;
				n = firstChild(t, n);
				cnt++;
				last = 0;
			}else if(hasNextSibling(t, n)){
				cout << "over;" << n << ";" << cnt << endl;
				n = nextSibling(t, n);
				cnt++;
				last = 1;
			}else{
				cout << "up;" << n << ";" << cnt << endl;
				n = parent(t, n);
				if(n==start)
					return cnt;
				last = 2;
			}
		}else if(last == 2){
			if(hasNextSibling(t, n)){
				cout << "over;" << n << ";" << cnt << endl;
				n = nextSibling(t, n);
				cnt++;
				last = 1;
			}else{
				cout << "up;" << n << ";" << cnt << endl;
				n = parent(t, n);
				if(n == start)
					return cnt;
				last = 2;
			}
		}
	}	
}
int sizeLogspace(Tree t, Node n){
	Node start = n;
	int last = 0; //0-down, 1-over, 2-up
	int cnt = 1;
	if(isLeaf(t, n)){
		return cnt;
	}
	n = firstChild(t, n);
	cnt++;
	
	while(true){
		if(last == 0 || last == 1){
			if(!isLeaf(t, n)){
				n = firstChild(t, n);
				cnt++;
				last = 0;
			}else if(hasNextSibling(t, n)){
				n = nextSibling(t, n);
				cnt++;
				last = 1;
			}else{
				n = parent(t, n);
				if(n==start)
					return cnt;
				last = 2;
			}
		}else if(last == 2){
			if(hasNextSibling(t, n)){
				n = nextSibling(t, n);
				cnt++;
				last = 1;
			}else{
				n = parent(t, n);
				if(n == start)
					return cnt;
				last = 2;
			}
		}
	}	
}