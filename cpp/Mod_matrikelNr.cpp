#pragma once
#include "Mod_removeDuplicates.cpp"

ListInt newList(ListInt mat, int mod){
	ListInt res;
	for(int i=0; i<length(mat); i++){
		res = append(res, sp_mod(get(mat, i), mod));
	}
	return res;
}

ListInt matrikelNr(ListInt mat){
	int mod = 10;
	while(true){
		ListInt nl = newList(mat, mod);
		if(length(removeDuplicates(nl)) != length (nl)){
			mod = mod*10;
		}else{
			return nl;
		}
	}
}
	