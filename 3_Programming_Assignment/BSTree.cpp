#include "BSTree.h"

#include <iostream>

using namespace std;

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement

// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream &operator<<(ostream &out, Node &node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream &operator>>(istream &in, BSTree &tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while (in >> next)
    {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
// If you try to use it without care, you will get a memory leak.
void BSTree::copy_helper(Node *&newNode, const Node *sourceNode)
{
    //Don't copy if the node is nullptr
    if (sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if (sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node *node)
{
    if (node != nullptr)
    {
        return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
    }
    return 0;
}

// implemented
float BSTree::get_average_search_time()
{
    int total_search_time = get_total_search_time(root);
    if (total_search_time == 0)
        return -1;

    return ((float)total_search_time) / size;
}

///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

//--------------------------------------------------------------------------//
//Copy and Move Constructor Grouping
//--------------------------------------------------------------------------//

void DestroyRec(Node* node);

void MoveRec(Node* nodeTo, Node* nodeFrom)
{
    nodeTo->value = nodeFrom->value;
    nodeTo->search_time = nodeFrom->search_time;
    if(nodeFrom->left != nullptr)
    {
        nodeTo->left = new Node();
        MoveRec(nodeTo->left, nodeFrom->left);
    } 
    if(nodeFrom->right != nullptr)
    {
        nodeTo->right = new Node();
        MoveRec(nodeTo->right, nodeFrom->right);
    }
    // nodeFrom->left = nullptr;
    // nodeFrom->right = nullptr;
    nodeFrom->search_time = 0;
    nodeFrom->value = 0;
    // delete nodeFrom;
    return;
}

void CopyRec(Node* nodeTo, Node* nodeFrom)
{
    nodeTo->value = nodeFrom->value;
    nodeTo->search_time = nodeFrom->search_time;
    if(nodeFrom->left != nullptr)
    {
        nodeTo->left = new Node();
        CopyRec(nodeTo->left, nodeFrom->left);
    } 
    if(nodeFrom->right != nullptr)
    {
        nodeTo->right = new Node();
        CopyRec(nodeTo->right, nodeFrom->right);
    }
    // nodeFrom->left = nullptr;
    // nodeFrom->right = nullptr;
    // nodeFrom->search_time = 0;
    // nodeFrom->value = 0;
    // delete nodeFrom;
    return;
}

void MoveConRec(Node* nodeTo, Node* nodeFrom)
{
    nodeTo->value = nodeFrom->value;
    nodeTo->search_time = nodeFrom->search_time;
    if(nodeFrom->left != nullptr)
    {
        nodeTo->left = new Node();
        MoveConRec(nodeTo->left, nodeFrom->left);
    } 
    if(nodeFrom->right != nullptr)
    {
        nodeTo->right = new Node();
        MoveConRec(nodeTo->right, nodeFrom->right);
    }
    // nodeFrom->left = nullptr;
    // nodeFrom->right = nullptr;
    nodeFrom->search_time = 0;
    nodeFrom->value = 0;
    // delete nodeFrom;
    return;
}

void CopyConRec(Node* nodeTo, Node* nodeFrom)
{
    nodeTo->value = nodeFrom->value;
    nodeTo->search_time = nodeFrom->search_time;
    if(nodeFrom->left != nullptr)
    {
        nodeTo->left = new Node();
        CopyConRec(nodeTo->left, nodeFrom->left);
    } 
    if(nodeFrom->right != nullptr)
    {
        nodeTo->right = new Node();
        CopyConRec(nodeTo->right, nodeFrom->right);
    }
    // nodeFrom->left = nullptr;
    // nodeFrom->right = nullptr;
    // nodeFrom->search_time = 0;
    // nodeFrom->value = 0;
    // delete nodeFrom;
    return;
}

// copy constructor
BSTree::BSTree(const BSTree &other)
{
    if(other.size == 0)
    {
        root = nullptr;
        size = 0;
        return;
    }
    Node* oroot = other.root;
    root = new Node();
    root->value = oroot->value;
    root->search_time = oroot->search_time;
    CopyConRec(root, other.root);
    size = other.size;
}

// move constructor
BSTree::BSTree(BSTree &&other)
{
    other.update_search_times();
    size = 0;
    if(other.size == 0)
    {
        root = nullptr;
    }
    size = other.size;
    root = other.root;
    other.root = nullptr;
    other.size = 0;

    // Node* oroot = other.root;
    // root = new Node();
    // root->value = oroot->value;
    // root->search_time = oroot->search_time;
    // MoveConRec(root, other.root);
    // size = other.size;
    // other.size = 0;
    // other.~BSTree();
}

//--------------------------------------------------------------------------//
//Copy and Move Assignment Grouping
//--------------------------------------------------------------------------//

//copy assignment
BSTree &BSTree::operator=(const BSTree &other)
{
    if(root == other.root)
    {
        return *this;
    }
    this->~BSTree();
    //DestroyRec(root);
    size = 0;
    if(other.size == 0)
    {
        root = nullptr;
        return *this;
    }
    root = new Node();
    root->value = other.root->value;
    root->search_time = other.root->search_time;
    CopyRec(root, other.root);
    size = other.size;
    return *this;
}

// move assignment
BSTree &BSTree::operator=(BSTree &&other)
{
    if(this->root == other.root)
    {
        return *this;
    }
    other.update_search_times();
    this->~BSTree();
    //DestroyRec(root);
    size = 0;
    if(other.size == 0)
    {
        root = nullptr;
        return *this;
    }
    size = other.size;
    root = other.root;
    other.root = nullptr;
    other.size = 0;

    // Node* oroot = other.root;
    // root = new Node();
    // root->value = oroot->value;
    // root->search_time = oroot->search_time;
    // MoveRec(root, other.root);
    // other.size = 0;
    // other.~BSTree();
    
    return *this;
}

//--------------------------------------------------------------------------//
//Destructor Grouping
//--------------------------------------------------------------------------//

void DestroyRec(Node* node)
{
    if(node == nullptr) return;
    if(node->left != nullptr) DestroyRec(node->left);
    if(node->right != nullptr) DestroyRec(node->right);
    node->left = nullptr;
    node->right = nullptr;
    node->search_time = 0;
    node->value = 0;
    delete node;
    return;
}

// destructor
BSTree::~BSTree()
{
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    DestroyRec(root);
    root = nullptr;
    size = 0;
    //std::cout << "DESTRUCTOR CALLED FOR [" << this << "]\n";
}

//--------------------------------------------------------------------------//
//Insert Grouping
//--------------------------------------------------------------------------//

Node* RecursiveAdd(Node* nodeToAdd, Node* node)
{
    if(nodeToAdd->value < node->value)
    {
        if(node->left != nullptr)
        {
            RecursiveAdd(nodeToAdd, node->left);
        }
        else
        {
            node->left = nodeToAdd;
            return nodeToAdd;
        }
    }
    if(nodeToAdd->value >= node->value)
    {
        if(node->right != nullptr)
        {
            RecursiveAdd(nodeToAdd, node->right);
        }
        else
        {
            node->right = nodeToAdd;
            return nodeToAdd;
        }
    }
    return nodeToAdd;
}

Node *BSTree::insert(int obj)
{
    Node* nodeToAdd = new Node(obj);
    if(root == nullptr)
    {
        nodeToAdd->search_time = 1;
        root = nodeToAdd;
        ++size;
        return root;   
    }
    RecursiveAdd(nodeToAdd, root);
    ++size;
    this->update_search_times();
    return nodeToAdd;
}

//--------------------------------------------------------------------------//
//Search Grouping
//--------------------------------------------------------------------------//

Node* RecSearch(int target, Node* node)
{
    if(node->value == target)
    {
        return node;
    }
    if(node->left == nullptr && node->right == nullptr) return nullptr;
    Node* lRes = nullptr;
    Node* rRes = nullptr;
    if(node->left != nullptr) lRes = RecSearch(target, node->left);
    if(node->right != nullptr) rRes = RecSearch(target, node->right);
    
    if(lRes != nullptr) return lRes;
    return rRes;
}

Node *BSTree::search(int obj)
{
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */
    return RecSearch(obj, root);
}

void CostUpdateRecursive(Node* node, int cost = 1)
{
    node->search_time = cost;
    if(node->left != nullptr) CostUpdateRecursive(node->left, cost + 1);
    if(node->right != nullptr) CostUpdateRecursive(node->right, cost + 1);
    return;
}

void BSTree::update_search_times()
{
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
    if(root == nullptr) return; 
    CostUpdateRecursive(root);
}

//--------------------------------------------------------------------------//
//Print Grouping
//--------------------------------------------------------------------------//

void PrintInorder(Node* node, ostream &out, int level = 1)
{
    if(node == nullptr)
    {
        cout << "Empty\n";
        return;
    }
    if(node->left != nullptr) PrintInorder(node->left, out, level + 1);
    out << node->value << "[" << level << "] ";
    if(node->right != nullptr) PrintInorder(node->right, out, level + 1);
}

void BSTree::inorder(ostream &out)
{
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
    if(root == nullptr)
    {
        out << "Empty\n";
        return;
    }
    PrintInorder(root, out);
    out << "\n";
}

void BSTree::print_level_by_level(ostream &out)
{
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */


    std::queue<Node*> q;
    q.push(root);
    int numInLevel = 1;
    int level = 1;
    bool moreChildExist = false;
    while(numInLevel > 0)
    {
        Node* node = q.front();
        q.pop();
        numInLevel--;
        if(node != nullptr)
        {
            out << node->value << "[" << level << "] ";
            if(node->left != nullptr || node->right !=nullptr)
            {
                moreChildExist = true;
            }
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            out << "X ";
            q.push(nullptr);
            q.push(nullptr);
        }
        if(numInLevel == 0)
        {
            out << "\n";
            if(moreChildExist == true)
            {
                moreChildExist = false;
                numInLevel = q.size();
                ++level;
            }
        }
    }
}
