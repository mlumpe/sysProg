#pragma once

Tuple2<Int, Int> findBoundary(List<Tuple2<String, String>> t, int start){
	Tuple2<String, String> first = get(t, start);
	String token = get21(first);
	String inhalt = get22(first);
	
	int po = 0;
	
	if(token == "VAR" || token == "TRUE" || token == "FALSE"){
		return tuple2(start, start);
	}else{ // = PO
		for(int i = start;;i++){
			token = get21(get(t, i));
			if(token == "PO")
				po++;
			else if(token == "PC")
				po--;

			if(po == 0)
				return tuple2(start, i);
		}	
	}
}

Tuple3<Tree, Map<Node, String>, Int> parseRec(List<Tuple2<String, String>> t, Tree tree, Node n, Map<Node, String> map, int id){
	Tuple2<String, String> first = get(t, 0);
	String token = get21(first);
	String inhalt = get22(first);
	
	
	if(token == "VAR"){
		map = setImage(map, n, inhalt);
		return tuple3(tree, map, id);
	}else if(token == "TRUE" || token == "FALSE"){
		map = setImage(map, n, token);
		return tuple3(tree, map, id);
	}else{ // = PO

		Tuple2<String, String> second = get(t, 1);
		token = get21(second);
		
		int endeErste;
		
		if(token == "NOT"){
			String rootToken = "NOT";
			map = setImage(map, n, rootToken);
			
			endeErste = 0;
			
			
		}else{//binär
			Tuple2<Int, Int> ersteFormel = findBoundary(t, 1);
			int startErste = get21(ersteFormel);
			endeErste = get22(ersteFormel);

			String rootToken = get21(get(t, endeErste+1));
			map = setImage(map, n, rootToken);

			Node newRoot1 = createNode(id);
			tree = addOwnLeaf(tree, n, newRoot1);
			Tuple3<Tree, Map<Node, String>, Int> teil1 = parseRec(sublist(t, startErste, (endeErste-startErste+1)), tree, newRoot1, map, id+1);

			tree = get31(teil1);
			map = get32(teil1);
			id = get33(teil1);
		}

		Tuple2<Int, Int> zweiteFormel = findBoundary(t, endeErste + 2);
		int startZweite = get21(zweiteFormel);
		int endeZweite = get22(zweiteFormel);
		
		Node newRoot2 = createNode(id);
		tree = addOwnLeaf(tree, n, newRoot2);
		Tuple3<Tree, Map<Node, String>, Int> teil2 = parseRec(sublist(t, startZweite, (endeZweite-startZweite+1)), tree, newRoot2, map, id+1);

		tree = get31(teil2);
		map = get32(teil2);
		id = get33(teil2);
	}
	return tuple3(tree, map, id);;
}

Tuple2<Tree, Map<Node, String>> parse(List<Tuple2<String, String>> t){
	Map<Node, String> map;
	int id = 1;
	Node root = createNode(id);
	Tree tree = newTreeOwn(root);
	id++;
	
	Tuple3<Tree, Map<Node, String>, Int> rec = parseRec(t, tree, root, map, id);
	return tuple2(get31(rec), get32(rec));
	
	
}

