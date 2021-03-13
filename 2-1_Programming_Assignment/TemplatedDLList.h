// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DLList; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode {
    T obj;
    DLListNode<T> *prev, *next;
    // constructor
    DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList {
private:
    DLListNode<T> header, trailer;
public:
    DLList() 
    {
        header;
        trailer;
        header.next = &trailer;
        trailer.prev = &header;
    }
    DLList(const DLList& dll) // copy constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
        DLListNode<T>* curr = dll.first_node();
        while(curr != dll.after_last_node())
        {
            this->insert_last(curr->obj);
            curr = curr->next;
        }
    } 
    DLList(DLList<T>&& dll) // move constructor
    {
        header;
        trailer;
        header.next = &trailer;
        trailer.prev = &header;


        while(!dll.is_empty())
        {
            this->insert_last(dll.remove_first());
        }
        dll.header;
        dll.trailer;

        dll.header.next = &dll.trailer;
        dll.trailer.prev = &dll.header;
    } 
    ~DLList() // destructor
    {
        DLListNode<T>* curr = header.next;
        while(curr != &trailer)
        {
            DLListNode<T>* toDell = curr;
            curr = curr->next;
            delete toDell;
            toDell = nullptr;
        }
        header;
        trailer;
    } 
    inline DLList<T>& operator=(const DLList<T>& dll) // copy assignment operator
    {
        header;

        DLListNode<T>* localPrev = &header;
        DLListNode<T>* curr = dll.first_node();
        while(curr != dll.after_last_node())
        {
            localPrev->next = new DLListNode<T>(curr->obj);
            localPrev->next->prev = localPrev;                //All these prevs give me cancer
            localPrev = localPrev->next;
            curr = curr->next;
        }
        
        trailer;
        localPrev->next = &trailer;
        trailer.prev = localPrev;
        return *this;
    } 
    inline DLList<T>& operator=(DLList<T>&& dll) // move assignment operator
    {
        this->~DLList<T>();
        header;
        trailer;
        header.next = &trailer;
        trailer.prev = &header;


        while(!dll.is_empty())
        {
            this->insert_last(dll.remove_first());
        }
        dll.header;
        dll.trailer;

        dll.header.next = &dll.trailer;
        dll.trailer.prev = &dll.header;
        return *this;
    } 
    inline DLListNode<T>* first_node() const // return the pointer to the first node (header's next)
    {
        return header.next;
    }
    inline const DLListNode<T>* after_last_node() const // return the pointer to the trailer 
    {
        return &trailer; 
    }
    inline bool is_empty() const // return if the list is empty
    {
        if(header.next == &trailer)
        {
            return true;
        }
        return false;
    }
    inline T first() const // return the first object
    {
        return header.next->obj;
    } 
    inline T last() const // return the last object
    {
        return trailer.prev->obj;
    } 
    inline void insert_first(T obj) // insert to the first node
    {
        DLListNode<T>* node = new DLListNode<T>(obj, &header, header.next);
        header.next->prev = node;
        header.next = node;
    } 
    inline T remove_first() // remove the first node
    {
        if(this->is_empty())
        {
            throw("List is empty");
        }   
        DLListNode<T>* toDel = header.next;
        header.next->next->prev = &header;
        header.next = header.next->next;
        T val = toDel->obj;
        delete toDel;
        return val;
    } 
    inline void insert_last(T obj) // insert to the last node
    {
        DLListNode<T>* node = new DLListNode<T>(obj, trailer.prev, &trailer);
        trailer.prev->next = node;
        trailer.prev = node;
    }
    inline T remove_last() // remove the last node
    {
        if(this->is_empty())
        {
            throw("List is empty");
        }
        DLListNode<T>* toDel = trailer.prev;
        trailer.prev->prev->next = &trailer;
        trailer.prev = trailer.prev->prev;
        T val = toDel->obj;
        delete toDel;
        return val;
    } 
    inline void insert_after(DLListNode<T> &p, T obj) 
    {
        DLListNode<T>* node = new DLListNode<T>(obj, &p, p.next);
        p.next->prev = node;
        p.next = node;
    }
    inline void insert_before(DLListNode<T> &p, T obj) 
    {
        DLListNode<T>* node = new DLListNode<T>(obj, p.prev, &p);
        p.prev->next = node;
        p.prev = node;
    }
    inline T remove_after(DLListNode<T> &p) 
    {
        if(this->is_empty())
        {
            throw("List is empty");
        }
        if(p.next == &trailer)
        {
            throw("This is the last element. You can't remove after this");
        }
        DLListNode<T>* toDel = p.next;
        p.next->next->prev = &p;
        p.next = p.next->next;
        T val = toDel->obj;
        delete toDel;
        return val;
    }
    inline T remove_before(DLListNode<T> &p) 
    {
        if(this->is_empty())
        {
            throw("List is empty");
        }
        if(p.prev == &header)
        {
            throw("This is the first element. You can't remove before this");
        }
        DLListNode<T>* toDel = p.prev;
        p.prev->prev->next = &p;
        p.prev = p.prev->prev;
        T val = toDel->obj;
        delete toDel;
        return val;
    }

};

// output operator
template <typename T>
inline ostream& operator<<(ostream& out, const DLList<T>& list)
{
    DLListNode<T>* curr = list.first_node();
    while(curr != list.after_last_node())
    {
        // if(curr->next == list.after_last_node())
        // {
        //     std::cout << curr->obj;
        //     break;    
        // }
        std::cout << curr->obj << ", ";
        curr = curr->next;
    }
    return out;
}


#endif
