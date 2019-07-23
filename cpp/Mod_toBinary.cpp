#pragma once

List<Int> toBinary(int from){
	List<Int> res;
	while(from > 0){
		res = prepend(res, sp_mod(from, 2));
		from = sp_div(from, 2);
	}
	if(empty(res))
		res = {0};
	return res;
}