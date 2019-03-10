#ifndef _NODE_HPP
#define _NODE_HPP

template <typename TK, typename TD>
//! A template node class, to be used in the BinarySearchTree class.
class Node      // done
{
public:
    //! Initializes left and right pointers to nullptr.
    Node()
    {
        ptrLeft = nullptr;
        ptrRight = nullptr;
        isTree = true;
    }

	Node(TK newKey, TD newData)
	{
		key = newKey;
		data = newData;
		ptrLeft = nullptr;
		ptrRight = nullptr;
		isTree = true;
	}



    void IsNotTree()
    {
        isTree = false;
    }

    //! Destroys left and right children, if they are not pointing to nullptr.
    ~Node()
    {
        if ( isTree )
        {
            // destroy children
            if ( ptrLeft != nullptr ) { delete ptrLeft; }
            if ( ptrRight != nullptr ) { delete ptrRight; }
        }
    }

    //! Pointer to the left child of the node, which is lesser in value
    Node<TK, TD>* ptrLeft;

    //! Pointer to the right chlid of the node, which is greater in value
    Node<TK, TD>* ptrRight;

    //! The data stored by the node
    TD data;

    //! The key of this node
    TK key;

    bool isTree;
};

#endif
