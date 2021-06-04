#include "BSTree.h"

using std::move;

int main()
{
    Node* searchRes = nullptr;
    BSTree tree;
    tree.insert(0);
    tree.insert(1);
    tree.insert(2);
    tree.insert(10);
    tree.insert(-2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    searchRes = tree.insert(6);

    tree.update_search_times();
    std::cout << "\n\nFound:    " << tree.search(6) << "\nExpected: " << searchRes << "\n";

    BSTree tree1;
    tree1.insert(6);
    tree1.insert(5);
    tree1.insert(232);
    tree1.insert(10000);
    tree1.insert(-221);
    tree1.insert(33);
    tree1.insert(-4);
    tree1.insert(-5);

    BSTree tree3;
    tree3.insert(1);
    tree3.insert(2);
    tree3.insert(3);
    tree3.insert(4);
    tree3.insert(5);
    tree3.insert(6);
    tree3.insert(7);
    tree3.insert(8);

    std::cout << "tree:                                       ";
    tree.inorder(std::cout);
    std::cout << "tree1:                                      ";
    tree1.inorder(std::cout);
    std::cout << "tree3:                                      ";
    tree3.inorder(std::cout);
    //tree.print_level_by_level(std::cout);


    BSTree tree2(move(tree));
    std::cout << "tree2 after move constructor from tree:     ";
    tree2.inorder(std::cout);
    tree2 = move(tree1);
    std::cout << "tree2 after move assignment from tree1:     ";
    tree2.inorder(std::cout);
    tree2 = tree3;
    std::cout << "tree2 after copy assignment from tree3:     ";
    tree2.inorder(std::cout);

    BSTree tree4(tree2);
    std::cout << "tree4 after copy constructor from tree2:    ";
    tree4.inorder(std::cout);

    std::cout << "tree:                                       ";
    tree.inorder(std::cout);
    std::cout << "tree1:                                      ";
    tree1.inorder(std::cout);
    std::cout << "tree2:                                      ";
    tree2.inorder(std::cout);
    std::cout << "tree3:                                      ";
    tree3.inorder(std::cout);
    std::cout << "tree4:                                      ";
    tree4.inorder(std::cout);

    tree2 = move(tree1);
    std::cout << "tree2 after move assignment from tree1:     ";
    tree2.inorder(std::cout);
    tree2 = move(tree3);
    std::cout << "tree2 after move assignment from tree3:     ";
    tree2.inorder(std::cout);
    tree2 = move(tree4);
    std::cout << "tree2 after move assignment from tree4:     ";
    tree2.inorder(std::cout);

    BSTree t1;
    BSTree t2;
    t2 = t1;

    std::cout << "\n\n";
    tree2.inorder(std::cout);
    tree2 = tree2;
    tree2.inorder(std::cout);


    return 0;
}