#pragma once

int fromBinary(List<Int> bin){
	int i = 0;
	int mult = 1;
	while(!empty(bin)){
		i += last(bin) * mult;
		mult = mult *2;
		bin = removeLast(bin);
	}
	
	return i;
}