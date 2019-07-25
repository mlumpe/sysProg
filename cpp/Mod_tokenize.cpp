#pragma once

List<Tuple2<String, String>> tokenize(String formel){
	List<Char> allowed = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
	List<Char> formChar = s2lc(formel);
	List<Tuple2<String, String>> res;
	
	for(int i=0; i<length(formChar); i++){
		String token;
		String in;
		switch(get(formChar, i)){
			case '(':
				token = "PO";
				in = "(";
				break;
			case ')':
				token = "PC";
				in = ")";
				break;
			case '0':
				token = "FALSE";
				in = "0";
				break;
			case '1':
				token = "TRUE";
				in = "1";
				break;
			case '!':
				token = "NOT";
				in = "!";
				break;
			case '&':
				token = "AND";
				in = "&&";
				i++;
				break;
			case '|':
				token = "OR";
				in = "||";
				i++;
				break;
			case '-':
				token = "IMPLY";
				in = "->";
				i++;
				break;
			case ' ':
				continue;
			default:
				token = "VAR";
				break;
		}
		
		if(token == "VAR"){
			while(contains(allowed, get(formChar, i))){
				in = append(in, get(formChar, i));
				i++;
			}
			i--;
		}
		res = append(res, tuple2(token, in));
	}
	return res;
}