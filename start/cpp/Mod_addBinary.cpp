#pragma once

/**List<Int> addBinary(List<Int> l1, List<Int> l2){
	int c = 0;
	List<Int> res;
	
	while(!(empty(l1) || empty(l2))){
		int x = last(l1) + last(l2) + c;
		if(x > 1){
			c=1;
			x = sp_mod(x,2);
		}else{
			c=0;
		}
		res = prepend(res, x);
		l1 = removeLast(l1);
		l2 = removeLast(l2);
	}
	
	while(!(empty(l1))){
		int x = last(l1) + c;
		if(x > 1){
			c=1;
			x = sp_mod(x,2);
		}else{
			c=0;
		}
		res = prepend(res, x);
		l1 = removeLast(l1);
	}
	while(!(empty(l2))){
		int x = last(l2) + c;
		if(x > 1){
			c=1;
			x = sp_mod(x,2);
		}else{
			c=0;
		}
		res = prepend(res, x);
		l2 = removeLast(l2);
	}
	
	if(c==1){
		res = prepend(res, 1);
	}
	return res;
}*/

List<Int> addBinary(List<Int> l1, List<Int> l2){
	int l1dec = fromBinary(l1);
	int l2dec = fromBinary(l2);
	return toBinary(l1dec+l2dec);
}