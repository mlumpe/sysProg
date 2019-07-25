#pragma once

Tuple2<Tree, Map<Node, String>> parse(List<Tuple2<String, String>> t){
	int i = 0;
	String token = getToken(t, i);
	i++;
	
	switch(token){
		case "FALSE":
			
	}
}

String getToken(List<Tuple2<String, String>> tokenized, int i){
	return get21(get(tokenized, i));
}