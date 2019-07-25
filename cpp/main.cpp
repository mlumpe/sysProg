#include "splib.cpp"
#include "types.cpp"

//Einbinden der selbst geschriebenen Programme
#include "Mod_treeToString.cpp"
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
    
    /* Tree t7 */
    Node v71 = createNode(1);
    Node v72 = createNode(2);
    Node v73 = createNode(3);
    Node v74 = createNode(4);
    Node v75 = createNode(5);
    Node v76 = createNode(6);
    Node v77 = createNode(7);
    Node v78 = createNode(8);
    Node v79 = createNode(9);
    Node v710 = createNode(10);
    Node v711 = createNode(11);
    Node v712 = createNode(12);
    Node v713 = createNode(13);
    Node v714 = createNode(14);
    Tree t7 = newTreeOwn(v71);
    t7 = addOwnLeaf(t7, v71, v72);
    t7 = addOwnLeaf(t7, v71, v74);
    t7 = addOwnLeaf(t7, v71, v78);
    
    t7 = addOwnLeaf(t7, v72, v73);
    t7 = addOwnLeaf(t7, v74, v75);
    t7 = addOwnLeaf(t7, v74, v76);
    t7 = addOwnLeaf(t7, v78, v79);
    t7 = addOwnLeaf(t7, v78, v710);
    t7 = addOwnLeaf(t7, v78, v712);

    t7 = addOwnLeaf(t7, v76, v77);
    t7 = addOwnLeaf(t7, v710, v711);
    t7 = addOwnLeaf(t7, v712, v713);

    t7 = addOwnLeaf(t7, v713, v714);

    //cout << treeToString(t7) << endl;

    /* Tree t8 */
    Node v81 = createNode(1);
    Node v82 = createNode(2);
    Node v83 = createNode(3);
    Node v84 = createNode(4);
    Node v85 = createNode(5);
    Node v86 = createNode(6);
    Node v87 = createNode(7);
    Node v88 = createNode(8);
    Node v89 = createNode(9);
    Node v810 = createNode(10);
    Node v811 = createNode(11);
    Node v812 = createNode(12);
    Node v813 = createNode(13);
    Node v814 = createNode(14);
    Tree t8 = newTreeOwn(v81);
    t8 = addOwnLeaf(t8, v81, v82);
    t8 = addOwnLeaf(t8, v81, v86);
    t8 = addOwnLeaf(t8, v81, v813);

    t8 = addOwnLeaf(t8, v82, v83);
    t8 = addOwnLeaf(t8, v82, v85);
    t8 = addOwnLeaf(t8, v86, v87);
    t8 = addOwnLeaf(t8, v86, v89);
    t8 = addOwnLeaf(t8, v86, v812);
    t8 = addOwnLeaf(t8, v813, v814);
    
    t8 = addOwnLeaf(t8, v83, v84);
    t8 = addOwnLeaf(t8, v87, v88);
    t8 = addOwnLeaf(t8, v89, v810);

    t8 = addOwnLeaf(t8, v810, v811);

    //cout << treeToString(t8) << endl;
    
    /* Tree t9 */
    Node v91 = createNode(1);
    Node v92 = createNode(2);
    Node v93 = createNode(3);
    Node v94 = createNode(4);
    Node v95 = createNode(5);
    Node v96 = createNode(6);
    Node v97 = createNode(7);
    Node v98 = createNode(8);
    Tree t9 = newTreeOwn(v91);
    t9 = addOwnLeaf(t9, v91, v92);
    t9 = addOwnLeaf(t9, v91, v95);

    t9 = addOwnLeaf(t9, v92, v93);
    t9 = addOwnLeaf(t9, v92, v94);
    t9 = addOwnLeaf(t9, v95, v96);
    t9 = addOwnLeaf(t9, v95, v98);
    
    t9 = addOwnLeaf(t9, v96, v97);

    //cout << treeToString(t9) << endl;
    
    /* Tree t10 */
    Node v101 = createNode(1);
    Node v102 = createNode(2);
    Node v103 = createNode(3);
    Node v104 = createNode(4);
    Node v105 = createNode(5);
    Node v106 = createNode(6);
    Node v107 = createNode(7);
    Node v108 = createNode(8);
    Tree t10 = newTreeOwn(v101);
    t10 = addOwnLeaf(t10, v101, v102);
    t10 = addOwnLeaf(t10, v101, v105);

    t10 = addOwnLeaf(t10, v102, v103);
    t10 = addOwnLeaf(t10, v105, v106);
    t10 = addOwnLeaf(t10, v105, v108);

    t10 = addOwnLeaf(t10, v103, v104);
    t10 = addOwnLeaf(t10, v106, v107);

    //cout << treeToString(t10) << endl;
    
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
