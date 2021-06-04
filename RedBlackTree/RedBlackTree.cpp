#include <iostream>
#include <string>
#include <vector>

enum COLOR {RED, BLACK};


struct TreeNode
{
    TreeNode* Parent = nullptr;
    TreeNode* lChild = nullptr;
    TreeNode* rChild = nullptr;
    TreeNode* Sibling = nullptr;
    int val;
    COLOR col;
    TreeNode(int value, COLOR color)
    {
        val = value;
        col = color;
    }
    void Recolor()
    {
        if(col == COLOR::RED) col == COLOR::BLACK;
        if(col == COLOR::BLACK) col == COLOR::RED;
    }
    bool Red()
    {
        if(col == COLOR::RED)
        {
            return true;
        }
        return false;
    }
    bool Black()
    {
        if(col == COLOR::BLACK)
        {
            return true;
        }
        return false;
    }
    bool IsLeftChild()
    {
        if(Parent->lChild == this)
        {
            return true;
        }
        return false;
    }
    bool IsRightChild()
    {
        if(Parent->rChild == this)
        {
            return true;
        }
        return false;
    }
    TreeNode* Uncle()
    {
        return Parent->Sibling;
    }
    TreeNode* Grandparent()
    {
        if(Parent != nullptr)
        {
            return Parent->Parent;
        }
        return nullptr;
    }
};


class RedBlackTree
{
public:
    TreeNode* root;
    RedBlackTree(int value)
    {
        root = new TreeNode(value, COLOR::BLACK);
    }
    
    TreeNode* RecursiveAdd(TreeNode* nodeToAdd, TreeNode* node)
    {
        if(nodeToAdd->val < node->val)
        {
            if(node->lChild != nullptr)
            {
                RecursiveAdd(nodeToAdd, node->lChild);
            }
            else
            {
                node->lChild = nodeToAdd;
                nodeToAdd->Parent = node;
                nodeToAdd->Sibling = node->rChild;
                return nodeToAdd;
            }
        }
        if(nodeToAdd->val >= node->val)
        {
            if(node->rChild != nullptr)
            {
                RecursiveAdd(nodeToAdd, node->rChild);
            }
            else
            {
                node->rChild = nodeToAdd;
                nodeToAdd->Parent = node;
                nodeToAdd->Sibling = node->lChild;
                return nodeToAdd;
            }
        }
    }



    TreeNode* Add(int val)
    {
        TreeNode* node = RecursiveAdd(new TreeNode(val, COLOR::RED), root);
        bool changed = true;
        while(changed)
        {
            changed = false;
            if(node->Grandparent() != nullptr)
            {
                if(node->Uncle() != nullptr && node->Uncle()->Red())
                {
                    changed = true;
                    node->Parent->Parent->Recolor();
                    node->Parent->Recolor();
                    if(node->Parent->Sibling != nullptr)
                    {
                        node->Parent->Sibling->Recolor();
                    }
                    node = node->Parent->Parent;
                }
                else if(node->IsLeftChild() && node->Parent->IsRightChild() && (node->Uncle() == nullptr || node->Uncle()->Black()))
                {
                    changed = true;
                    RotateRight(node);
                }
                else if(node->IsRightChild() && node->Parent->IsLeftChild() && (node->Uncle() == nullptr || node->Uncle()->Black()))
                {
                    changed = true;
                    RotateLeft(node);
                }
                else if(node->IsRightChild() && node->Parent->IsRightChild() && (node->Uncle() == nullptr || node->Uncle()->Black()))
                {
                    changed = true;
                    RotateLeft(node->Parent);
                    node->Parent->Recolor();
                    node->Sibling->Recolor();
                }
                else if(node->IsLeftChild() && node->Parent->IsLeftChild() && (node->Uncle() == nullptr || node->Uncle()->Black()))
                {
                    changed = true;
                    RotateRight(node->Parent);
                    node->Parent->Recolor();
                    node->Sibling->Recolor();
                }
            }
            root->col = COLOR::BLACK;
        }
    }
};

void HandleReorient(TreeNode* current)
{
    current->Recolor();
    current->lChild->Recolor();
    current->rChild->Recolor();
}

void RotateRight(TreeNode* node)
{
    if(node->Parent == node->Parent->Parent->rChild)
    {
        TreeNode* oldGrandParent = node->Parent->Parent;
        TreeNode* oldParent = node->Parent;
        TreeNode* oldParentSibling = node->Parent->Sibling;
        node->Parent->Parent->rChild = node;
        node->Parent->lChild = node->rChild;
        node->rChild = node->Parent;
        node->Parent = oldGrandParent;
        oldParent->Sibling = node->Sibling;
        node->Sibling = oldParentSibling;
    }
    else if(node->Parent == node->Parent->Parent->lChild)
    {
        TreeNode* oldGrandParent = node->Parent->Parent;
        TreeNode* oldParent = node->Parent;
        TreeNode* oldParentSibling = node->Parent->Sibling;
        node->Parent->Parent->lChild = node;
        node->Parent->lChild = node->rChild;
        node->rChild = node->Parent;
        node->Parent = oldGrandParent;
        oldParent->Sibling = node->Sibling;
        node->Sibling = oldParentSibling;
    }
}

void RotateLeft(TreeNode* node)
{
    if(node->Parent == node->Parent->Parent->rChild)
    {
        TreeNode* oldGrandParent = node->Parent->Parent;
        TreeNode* oldParent = node->Parent;
        TreeNode* oldParentSibling = node->Parent->Sibling;
        node->Parent->Parent->rChild = node;
        node->Parent->rChild = node->lChild;
        node->lChild = node->Parent;
        node->Parent = oldGrandParent;
        oldParent->Sibling = node->Sibling;
        node->Sibling = oldParentSibling;
    }
    else if(node->Parent == node->Parent->Parent->lChild)
    {
        TreeNode* oldGrandParent = node->Parent->Parent;
        TreeNode* oldParent = node->Parent;
        TreeNode* oldParentSibling = node->Parent->Sibling;
        node->Parent->Parent->lChild = node;
        node->Parent->rChild = node->lChild;
        node->lChild = node->Parent;
        node->Parent = oldGrandParent;
        oldParent->Sibling = node->Sibling;
        node->Sibling = oldParentSibling;
    }
}


struct Triple
{
    int val;
    int level;
    int relPos;
    Triple(int value, int Level, int RelPos)
    {
        val = value;
        level = Level;
        relPos = RelPos;
    }
};

void ScaleTriplePos(std::vector<Triple>& v)
{
    int min = 0;
    for(Triple t : v)
    {
        if(t.relPos < min)
        {
            min = t.relPos;
        }
    }
    for(int i = 0; i < v.size(); ++i)
    {
        v[i].relPos -= min;
    }
}

int Max(int i1, int i2)
{
    if(i1 >= i2) return i1;
    return i2;
}

int TreeHeight(TreeNode* root)
{
    if(root == nullptr) return 0;
    return 1 + Max(TreeHeight(root->lChild), TreeHeight(root->rChild));
}

void TreeTextTriple(std::vector<Triple>* vec, TreeNode* root, int level = 0, int relPos = 0)
{
    if(root == nullptr)
    {
        return;
    }
    vec->push_back(Triple(root->val, level, relPos));
    TreeTextTriple(vec, root->lChild, level + 1, relPos - 1);
    TreeTextTriple(vec, root->rChild, level + 1, relPos + 1);
}

void PrintTree(RedBlackTree& tree)
{
    std::vector<Triple> TreeTriples;
    int levels = TreeHeight(tree.root);
    TreeTextTriple(&TreeTriples, tree.root);
    //int leftDex = TreeLeftDexFromTriple(TreeTriples);
    ScaleTriplePos(TreeTriples);

    for(int i = 0; i < levels; ++i)
    {
        int curPos = 0;
        for(Triple t : TreeTriples)
        {
            if(t.level == i)
            {
                while(curPos < t.relPos)
                {
                    std::cout << "\t";
                    curPos++;
                }
                std::cout << t.val;
            }
        }
        std::cout << "\n\n";
    }
}



int main()
{
    RedBlackTree tree(0);
    tree.Add(-1);
    tree.Add(1);
    tree.Add(2);
    tree.Add(4);
    PrintTree(tree);
}