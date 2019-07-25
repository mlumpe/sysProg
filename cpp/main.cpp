#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_sizeLogspace.cpp"
#include "Mod_nonRecursiveCheck.cpp"


int main() {  
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
    cout << "sizeLogspace(t1, v1)" << endl;
    cout << sizeLogspace(t1, createNode(1)) << endl;
    cout << "sizeLogspace(t2, v2)" << endl;
    cout << sizeLogspace(t2, createNode(2)) << endl;
    cout << "sizeLogspace(t4, v3)" << endl;
    cout << sizeLogspace(t4, createNode(3)) << endl;
    cout << "nonRecursiveCheck(t1, t1, v1, v1)" << endl;
    cout << nonRecursiveCheck(t1, t1, createNode(1), createNode(1)) << endl;
    cout << "nonRecursiveCheck(t3, t2, v5, v1)" << endl;
    cout << nonRecursiveCheck(t3, t2, createNode(5), createNode(1)) << endl;
	
    
    return 0;
}
