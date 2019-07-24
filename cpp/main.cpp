#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme

#include "Mod_subtree.cpp"
#include "Mod_multiplyList.cpp"
#include "Mod_treeToString.cpp"
#include "Mod_absolute.cpp"
#include "Mod_factorial.cpp"
#include "Mod_fibonacci.cpp"
#include "Mod_isPrime.cpp"
#include "Mod_nthPrime.cpp"
#include "Mod_toBinary.cpp"
#include "Mod_fromBinary.cpp"
#include "Mod_addBinary.cpp"
#include "Mod_multBinary.cpp"
#include "Mod_addKAry.cpp"
#include "Mod_firstChild.cpp"
#include "Mod_allNodes.cpp"
#include "Mod_removeSubtree.cpp"
#include "Mod_nextSibling.cpp"
#include "Mod_hasNextSibling.cpp"
#include "Mod_isomorphism.cpp"
#include "Mod_depth.cpp"


int main() {  
	/* Tree t1 */
    Tree t1 = newTree();
    Node v11 = root(t1);

    /* Tree t2 */
    Tree t2 = newTree();
    Node v21 = root(t2);
    t2 = addLeaf(t2, v21);
    t2 = addLeaf(t2, v21);
    Node v22 = get(children(t2, v21), 0);
    Node v23 = get(children(t2, v21), 1);
    t2 = addLeaf(t2, v22);
    t2 = addLeaf(t2, v22);
    Node v24 = get(children(t2, v22), 0);
    Node v25 = get(children(t2, v22), 1);
    t2 = addLeaf(t2, v25);
    t2 = addLeaf(t2, v25);
    t2 = addLeaf(t2, v25);
    Node v26 = get(children(t2, v25), 0);
    Node v27 = get(children(t2, v25), 1);
    Node v28 = get(children(t2, v25), 2);
    t2 = addLeaf(t2, v23);
    Node v29 = get(children(t2, v23), 0);

    /* Tree t3*/
    Node v35 = createNode(5);
    Node v36 = createNode(6);
    Node v37 = createNode(7);
    Node v38 = createNode(8);
    Tree t3 = newTreeOwn(v35);
    t3 = addOwnLeaf(t3, v35, v36);
    t3 = addOwnLeaf(t3, v35, v37);
    t3 = addOwnLeaf(t3, v35, v38);

    /* Tree t4 */
    Tree t4 = newTree();
    Node v41 = root(t4);
    t4 = addLeaf(t4, v41);
    t4 = addLeaf(t4, v41);
    Node v42 = get(children(t4, v41), 0);
    Node v43 = get(children(t4, v41), 1);
    t4 = addLeaf(t4, v42);
    Node v44 = get(children(t4, v42), 0);
    Node v49 = createNode(9);
    t4 = addOwnLeaf(t4, v43, v49);

    /* Tree t5 */
    Tree t5 = newTree();
    Node v51 = root(t5);
    Node v53 = createNode(3);
    Node v59 = createNode(9);
    t5 = addOwnLeaf(t5, v51, v53);
    t5 = addOwnLeaf(t5, v53, v59);
    
    /* Tree t6 */
    Node v66 = createNode(6);
    Node v62 = createNode(2);
    Node v69 = createNode(9);
    Node v61 = createNode(1);
    Node v64 = createNode(4);
    Node v65 = createNode(5);
    Node v618 = createNode(18);
    Node v67 = createNode(7);
    Node v63 = createNode(3);
    Tree t6 = newTreeOwn(v66);
    t6 = addOwnLeaf(t6, v66, v62);
    t6 = addOwnLeaf(t6, v66, v69);
    t6 = addOwnLeaf(t6, v62, v61);
    t6 = addOwnLeaf(t6, v62, v64);
    t6 = addOwnLeaf(t6, v64, v618);
    t6 = addOwnLeaf(t6, v64, v67);
    t6 = addOwnLeaf(t6, v64, v63);
    t6 = addOwnLeaf(t6, v69, v65);

    //Code zum Testen    
    cout << "*** Tests ***" << endl;
	cout << "treeToString(t1)" << endl;
	cout << treeToString(t1) << endl;
	cout << "treeToString(t2)" << endl;
	cout << treeToString(t2) << endl;
	cout << "treeToString(t3)" << endl;
	cout << treeToString(t3) << endl;
	cout << "treeToString(t4)" << endl;
	cout << treeToString(t4) << endl;
	cout << "treeToString(t5)" << endl;
	cout << treeToString(t5) << endl;
	cout << "treeToString(t6)" << endl;
	cout << treeToString(t6) << endl;
    
    
    cout << "firstChild(Tree, Node)" << endl;
    cout << "firstChild(t2, v25)" << endl;
    cout << firstChild(t2, v25) << endl;
    cout << "firstChild(t2, v23)" << endl;
    cout << firstChild(t2, v23) << endl;
    cout << "firstChild(t2, v22)" << endl;
    cout << firstChild(t2, v22) << endl;
    
    //cout << "nextSibling(Tree, Node)" << endl;
    //cout << nextSibling(t2, v26) << endl;
    
    cout << "allNodes(Tree)" << endl;
    cout << "allNodes(t1)" << endl;
    cout << allNodes(t1) << endl;
    cout << "allNodes(t2)" << endl;
    cout << allNodes(t2) << endl;
    cout << "allNodes(t4)" << endl;
    cout << allNodes(t4) << endl;
    cout << "allNodes(t5)" << endl;
    cout << allNodes(t5) << endl;

    cout << "removeSubtree(Tree, Node)" << endl;
    cout << "removeSubtree(t2, v5)" << endl;
    cout << removeSubtree(t2, v25) << endl;
    cout << "removeSubtree(t2, v2)" << endl;
    cout << removeSubtree(t2, v22) << endl;

    cout << "nextSibling(t2, v6)" << endl;
    cout << nextSibling(t2, v26) << endl;
    cout << "nextSibling(t2, v7)" << endl;
    cout << nextSibling(t2, v27) << endl;
    cout << "nextSibling(t2, v4)" << endl;
    cout << nextSibling(t2, v24) << endl;
    
    cout << "hasNextSibling(Tree, Node)" << endl;
    cout << "hasNextSibling(t2, v1)" << endl;
    cout << hasNextSibling(t2, v21) << endl;
    cout << "hasNextSibling(t2, v2)" << endl;
    cout << hasNextSibling(t2, v22) << endl;
    cout << "hasNextSibling(t2, v3)" << endl;
    cout << hasNextSibling(t2, v23) << endl;
    cout << "hasNextSibling(t2, v7)" << endl;
    cout << hasNextSibling(t2, v27) << endl;
    cout << "hasNextSibling(t2, v8)" << endl;
    cout << hasNextSibling(t2, v28) << endl;
    
    cout << "isomorphism(Tree, Tree)" << endl;
    cout << "isomorphism(t2, t6)" << endl;
    cout << isomorphism(t2, t6) << endl;
    cout << "isomorphism(t1, t2)" << endl;
    cout << isomorphism(t1, t2) << endl;
    
    cout << "depth(Tree)" << endl;
    cout << "depth(t1)" << endl;
    cout << depth(t1) << endl;
    cout << "depth(t2)" << endl;
    cout << depth(t2) << endl;
    cout << "depth(t5)" << endl;
    cout << depth(t5) << endl;
    cout << "depth(t6)" << endl;
    cout << depth(t6) << endl;
    cout << "depth(t3)" << endl;
    cout << depth(t3) << endl;
    
    return 0;
}
