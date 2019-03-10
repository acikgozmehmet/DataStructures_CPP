#ifndef _NODE_HPP
#define _NODE_HPP

template <typename T>
struct Node
{
    public:
    Node();

    Node* ptrNext;
    Node* ptrPrev;

    T data;
};

template <typename T>
Node<T>::Node()
{
    ptrNext = ptrPrev = nullptr;
}

#endif
