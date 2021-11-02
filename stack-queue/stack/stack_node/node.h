#ifndef _NODE_INCLUDED_
#define _NODE_INCLUDED_

template <typename T>  class node {
    private: 
        T value;
        node * prev;
    public:
        node();
        node(T);
        node(T, node*);
        node* setValue(T);
        node* setPrev(node*);
        T getValue() const;
        node* getPrev() const;
};

#endif