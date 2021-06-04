#include <vector>
#include <iostream>

template <typename T>
struct Node
{
    Node<T> *left, *right;
    T obj;

    Node(T obj, Node<T> *left = nullptr, Node<T> *right = nullptr)
        : obj(obj), left(left), right(right)
    {
    }
};

template <typename T>
int count_filled_nodes(const Node<T> *node)
{
    if(node->left != nullptr && node->right != nullptr)
    {
        int numNodes = 0;
        numNodes += count_filled_nodes(node->left);
        numNodes += count_filled_nodes(node->right);
        return 1 + numNodes;
    }
    else
    {
        if(node->left != nullptr)
        {
            return count_filled_nodes(node->left);
        }
        else if(node->right != nullptr)
        {
            return count_filled_nodes(node->right);
        }    
    }
    return 0;
}


int main()
{
    Node<int>* curr = new Node<int>(0,
        new Node<int>(0,
            new Node<int>(1,
                new Node<int>(2),
                new Node<int>(2)
            ),
            new Node<int>(1,
                new Node<int>(2),
                new Node<int>(2)
            )
        ),
        new Node<int>(0,
            new Node<int>(1,
                new Node<int>(2),
                new Node<int>(2)
            ),
            new Node<int>(1,
                new Node<int>(2),
                new Node<int>(2)
            )
        )    
    );

    std::cout << "Test 1: " << count_filled_nodes(curr) << "\t\tExpected 7" << "\n";

    Node<int>* curr2 = new Node<int>(0,
        new Node<int>(0,
            new Node<int>(1,
                new Node<int>(2,
                    new Node<int>(3,
                        new Node<int>(4),
                        new Node<int>(4,
                            new Node<int>(5),
                            new Node<int>(5,
                                new Node<int>(6,
                                    new Node<int>(7)
                                ),
                                new Node<int>(6)
                            )
                        )
                    )
                ),
                new Node<int>(2)
            ),
            new Node<int>(1,
                new Node<int>(2),
                new Node<int>(2)
            )
        ),
        new Node<int>(0,
            new Node<int>(1,
                new Node<int>(2)
            ),
            new Node<int>(1,
                new Node<int>(2,
                    new Node<int>(3),
                    new Node<int>(3)
                ),
                new Node<int>(2)
            )
        )    
    );

    std::cout << "Test 2: " << count_filled_nodes(curr2) << "\t\tExpected 10" << "\n";
}