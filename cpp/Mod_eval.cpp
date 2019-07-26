#pragma once

Tuple2<Tree, Map<Node, String>> eval(Tuple2<Tree, Map<Node, String>> ast){
	Map<Node, String> map = get22(ast);
	Tree tree = get21(ast);
	
	String trueS = "TRUE";
	String falseS = "FALSE";
	String notS = "NOT";
	String andS = "AND";
	String orS = "OR";
	String implyS = "IMPLY";
	
	bool done = 0;
	
	while(!done){
		done = 1;
		
		List<Node> nots = inverseOf(map, notS);

		for(int i = 0; i<length(nots); i++){

			Node notNode = get(nots, i);
			Node child = get(children(tree, notNode), 0);
			if(!isLeaf(tree, child))
				continue;
			if(imageOf(map, child) == trueS){
				done = 0;
				tree = removeLeaf(tree, child);
				map = setImage(map, notNode, falseS);
				map = undefine(map,child);
			}else if (imageOf(map, child) == falseS){
				done = 0;
				tree = removeLeaf(tree, child);
				map = setImage(map, notNode, trueS);
				map = undefine(map,child);
			}
		}

		List<Node> ands = inverseOf(map, andS);

		for(int i = 0; i<length(ands); i++){
			Node andNode = get(ands, i);
			Node child1 = get(children(tree, andNode), 0);
			Node child2 = get(children(tree, andNode), 1);
			if(!isLeaf(tree, child1) || !isLeaf(tree, child2))
				continue;
			if(imageOf(map, child1) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, andNode, imageOf(map, child2));
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child1) == falseS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, andNode, falseS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, andNode, imageOf(map, child1));
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == falseS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, andNode, falseS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}

		}


		List<Node> ors = inverseOf(map, orS);

		for(int i = 0; i<length(ors); i++){
			Node orNode = get(ors, i);
			Node child1 = get(children(tree, orNode), 0);
			Node child2 = get(children(tree, orNode), 1);
			if(!isLeaf(tree, child1) || !isLeaf(tree, child2))
				continue;
			if(imageOf(map, child1) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, orNode, trueS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child1) == falseS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, orNode, imageOf(map, child2));
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, orNode, trueS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == falseS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, orNode, imageOf(map, child1));
				map = undefine(map,child1);
				map = undefine(map,child2);
			}
		}


		List<Node> implys = inverseOf(map, implyS);

		for(int i = 0; i<length(implys); i++){
			Node implyNode = get(implys, i);
			Node child1 = get(children(tree, implyNode), 0);
			Node child2 = get(children(tree, implyNode), 1);
			if(!isLeaf(tree, child1) || !isLeaf(tree, child2))
				continue;
			if(imageOf(map, child1) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, implyNode, imageOf(map, child2));
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child1) == falseS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, implyNode, trueS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == trueS){
				done = 0;
				tree = removeLeaf(tree, child1);
				tree = removeLeaf(tree, child2);
				map = setImage(map, implyNode, trueS);
				map = undefine(map,child1);
				map = undefine(map,child2);
			}else if (imageOf(map, child2) == falseS){
				done = 0;
				tree = removeLeaf(tree, child2);
				map = setImage(map, implyNode, notS);
				map = undefine(map,child2);
			}
		}
		
	}

	return tuple2(tree, map);
}