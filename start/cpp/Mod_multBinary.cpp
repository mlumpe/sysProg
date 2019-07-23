#pragma once

/**List<Int> multBinary(List<Int> l1, List<Int> l2){
	List<List<Int>> toAdd;
	
	int i = 0;
	while(i<length(l1)){
		int shift = length(l1)-1-i;
		if(get(l1, i) == 1){
			List<Int> tmp = l2;
			for(int j = 0; j<shift; j++){
				tmp = append(tmp, 0);	
			}
			toAdd = append(toAdd, tmp);
		}
		i++;
	}
	List<Int> res = {0};
	for (i = 0; i<length(toAdd); i++){
		res = addBinary(res, get(toAdd,i));
	}
	return res;	  
}*/

List<Int> multBinary(List<Int> l1, List<Int> l2){
	int l1dec = fromBinary(l1);
	int l2dec = fromBinary(l2);
	return toBinary(l1dec*l2dec);
}