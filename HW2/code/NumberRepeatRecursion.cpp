#include <iostream>

template <typename T>
struct Node
{
    Node *next;
    T obj;

    Node(T obj, Node *next = nullptr)
        : obj(obj), next(next)
    { }
};

template <typename T>
int count_nodes(Node<T>* n)
{
    while(n->next != nullptr)
    {
        return 1 + count_nodes(n->next);
    }
    return 1;
}


int main()
{
    Node<int>* n1 = new Node<int>(0);
    Node<int>* first = n1;
    n1->next = new Node<int>(4); n1 = n1->next;
    n1->next = new Node<int>(3); n1 = n1->next;
    n1->next = new Node<int>(6); n1 = n1->next;
    n1->next = new Node<int>(2); n1 = n1->next;
    n1->next = new Node<int>(7); n1 = n1->next;
    n1->next = new Node<int>(8); n1 = n1->next;
    n1->next = new Node<int>(1);

    std::cout << "First Test:\n\nSize: ";
    std::cout << count_nodes<int>(first);


    Node<int>* n2 = new Node<int>(0);
    first = n2;
    n2->next = new Node<int>(2); n2 = n2->next;
    n2->next = new Node<int>(5); n2 = n2->next;
    n2->next = new Node<int>(68); n2 = n2->next;
    n2->next = new Node<int>(232); n2 = n2->next;
    n2->next = new Node<int>(713241534); n2 = n2->next;
    n2->next = new Node<int>(86); n2 = n2->next;
    n2->next = new Node<int>(0); n2 = n2->next;
    n2->next = new Node<int>(1); n2 = n2->next;
    n2->next = new Node<int>(2); n2 = n2->next;
    n2->next = new Node<int>(3); n2 = n2->next;
    n2->next = new Node<int>(12);

    std::cout << "\n\n\n\nSecond Test:\n\nSize: ";
    std::cout << count_nodes<int>(first) << "\n";
}