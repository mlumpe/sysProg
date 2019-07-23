#pragma once

template <typename T>
List<T> removeDuplicates(List<T> input){
	List<T> res;
	for(int i=0; i<length(input);i++){
		if(!contains(res, get(input, i))){
			res = append(res, get(input, i));
		}
	}
	return res;
}