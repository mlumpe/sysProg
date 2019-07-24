#pragma once

bool equals(List<Char> window, List<Char> pattern){
	for(int i=0; i<length(window); i++){
		if(get(pattern, i) == '*')
			continue;
		if(get(pattern, i) != get(window, i))
			return false;
	}
	return true;
}

List<Int> stream(String str, String pat){
	List<Char> s = s2lc(str);
	List<Char> pattern = s2lc(pat);
	List<Char> window;
	List<Int> result;
	int i;
	for(i = 0; i<length(pattern); i++){
		if(empty(s)){
			return {};
		}
		Char f = first(s);
		window = append(window, f);
		s = removeFirst(s);
	}
	while(!empty(s)){
		if(equals(window, pattern)){
			result = append(result, i-length(pattern));
		}
		Char f = first(s);
		s = removeFirst(s);
		window = removeFirst(window);
		window = append(window, f);
		i++;
	}
	if(equals(window, pattern)){
		result = append(result, i-length(pattern));
	}
	return result;
}

