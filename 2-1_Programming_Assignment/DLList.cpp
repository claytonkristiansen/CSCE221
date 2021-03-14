// implementation of the DLList class

#include "DLList.h"



DLList::DLList() 
{
    header = 0;
    trailer = 0;
    header.next = &trailer;
    trailer.prev = &header;
}
DLList::DLList(const DLList& dll) // copy constructor
{
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode* curr = dll.first_node();
    while(curr != dll.after_last_node())
    {
        this->insert_last(curr->obj);
        curr = curr->next;
    }
} 
DLList::DLList(DLList&& dll) // move constructor
{
    header = 0;
    trailer = 0;
    header.next = &trailer;
    trailer.prev = &header;


    while(!dll.is_empty())
    {
        this->insert_last(dll.remove_first());
    }
    dll.header = 0;
    dll.trailer = 0;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
} 
DLList::~DLList() // destructor
{
    DLListNode* curr = header.next;
    while(curr != &trailer)
    {
        DLListNode* toDell = curr;
        curr = curr->next;
        delete toDell;
        toDell = nullptr;
    }
    header = 0;
    trailer = 0;
} 
DLList& DLList::operator=(const DLList& dll) // copy assignment operator
{
    header = 0;
    // trailer = DLListNode(dll.last());

    DLListNode* localPrev = &header;
    DLListNode* curr = dll.first_node();
    while(curr != dll.after_last_node())
    {
        localPrev->next = new DLListNode(curr->obj);
        localPrev->next->prev = localPrev;                //All these prevs give me cancer
        localPrev = localPrev->next;
        curr = curr->next;
    }
    
    trailer = DLListNode(curr->obj);
    localPrev->next = &trailer;
    trailer.prev = localPrev;
    return *this;
} 
DLList& DLList::operator=(DLList&& dll) // move assignment operator
{
    this->~DLList();
    header = 0;
    trailer = 0;
    header.next = &trailer;
    trailer.prev = &header;


    while(!dll.is_empty())
    {
        this->insert_last(dll.remove_first());
    }
    dll.header = 0;
    dll.trailer = 0;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    return *this;
} 
DLListNode *DLList::first_node() const // return the pointer to the first node (header's next)
{
    return header.next;
}
const DLListNode *DLList::after_last_node() const // return the pointer to the trailer 
{
    return &trailer; 
}
bool DLList::is_empty() const // return if the list is empty
{
    if(header.next == &trailer)
    {
        return true;
    }
    return false;
}
int DLList::first() const // return the first object
{
    return header.next->obj;
} 
int DLList::last() const // return the last object
{
    return trailer.prev->obj;
} 
void DLList::insert_first(int obj) // insert to the first node
{
    DLListNode* node = new DLListNode(obj, &header, header.next);
    header.next->prev = node;
    header.next = node;
} 
int DLList::remove_first() // remove the first node
{
    if(this->is_empty())
    {
        throw("List is empty");
    }
    DLListNode* toDel = header.next;
    header.next->next->prev = &header;
    header.next = header.next->next;
    int val = toDel->obj;
    delete toDel;
    return val;
} 
void DLList::insert_last(int obj) // insert to the last node
{
    DLListNode* node = new DLListNode(obj, trailer.prev, &trailer);
    trailer.prev->next = node;
    trailer.prev = node;
}
int DLList::remove_last() // remove the last node
{
    if(this->is_empty())
    {
        throw("List is empty");
    }
    DLListNode* toDel = trailer.prev;
    trailer.prev->prev->next = &trailer;
    trailer.prev = trailer.prev->prev;
    int val = toDel->obj;
    delete toDel;
    return val;
} 
void DLList::insert_after(DLListNode &p, int obj) 
{
    DLListNode* node = new DLListNode(obj, &p, p.next);
    p.next->prev = node;
    p.next = node;
}
void DLList::insert_before(DLListNode &p, int obj) 
{
    DLListNode* node = new DLListNode(obj, p.prev, &p);
    p.prev->next = node;
    p.prev = node;
}
int DLList::remove_after(DLListNode &p) 
{
    if(this->is_empty())
    {
        throw("List is empty");
    }
    if(p.next == &trailer)
    {
        throw("This is the last element. You can't remove after this");
    }
    DLListNode* toDel = p.next;
    p.next->next->prev = &p;
    p.next = p.next->next;
    int val = toDel->obj;
    delete toDel;
    return val;
}
int DLList::remove_before(DLListNode &p) 
{
    if(this->is_empty())
    {
        throw("List is empty");
    }
    if(p.prev == &header)
    {
        throw("This is the first element. You can't remove before this");
    }
    DLListNode* toDel = p.prev;
    p.prev->prev->next = &p;
    p.prev = p.prev->prev;
    int val = toDel->obj;
    delete toDel;
    return val;
}



ostream &operator<<(ostream &os, const DLList &list)
{
    DLListNode* curr = list.first_node();
    while(curr != list.after_last_node())
    {
        // if(curr->next == list.after_last_node())
        // {
        //     std::cout << curr->obj << "\n";
        //     break;    
        // }
        std::cout << curr->obj << ", ";
        curr = curr->next;
    }
    return os;
}