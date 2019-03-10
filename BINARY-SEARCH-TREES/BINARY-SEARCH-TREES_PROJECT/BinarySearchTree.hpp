/* Modify this file! */

#ifndef _BINARY_SEARCH_TREE_HPP
#define _BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Node.hpp"

template <typename TK, typename TD>
//! A template binary search tree class that takes a KEY and a DATA
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    // Basic functionality
    void Push( const TK& newKey, const TD& newData );
    void Delete( const TK& key );
    bool Contains( const TK& key );
    bool RecursiveContains( const TK& key, Node<TK, TD>* ptrCurrent );
    TD* GetData( const TK& key );
    Node<TK, TD>* FindNode( const TK& key );

    // Traversal functions - Recursive entry
    string GetInOrder();
    string GetPreOrder();
    string GetPostOrder();

    // Additional functionality - Recursive entry
    TK* GetMinKey();
    TK* GetMaxKey();
    int GetCount();
    int GetHeight();

private:
    Node<TK, TD>* RecursiveFindNode( const TK& key, Node<TK, TD>* ptrCurrent );
    Node<TK, TD>* FindParentOfNode( const TK& key );

    void RecursivePush( const TK& newKey, const TD& newData, Node<TK, TD>* ptrCurrent );

    // Recursive traversal functions
    void GetInOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );
    void GetPreOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );
    void GetPostOrder( Node<TK, TD>* ptrCurrent, stringstream& stream );

    // Recursive additional functionality
    TK* GetMax( Node<TK, TD>* ptrCurrent );
    TK* GetMin( Node<TK, TD>* ptrCurrent );
    int GetHeight( Node<TK, TD>* ptrCurrent );

    // Delete functions
    void DeleteNode_NoChildren( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode );
    void DeleteNode_LeftChild( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode );
    void DeleteNode_RightChild( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode );
    void DeleteNode_TwoChildren( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode );

private:
    //! A pointer to the root node of the tree; TK = data type of the key, TD = data type of the data.
    Node<TK, TD>* m_ptrRoot;

    //! The amount of nodes in the tree
    int m_nodeCount;

friend class Tester;
};

//! Initializes the node count to 0, and the root pointer to nullptr.
template <typename TK, typename TD>
BinarySearchTree<TK,TD>::BinarySearchTree()	// done
{
    m_ptrRoot = nullptr;
    m_nodeCount = 0;
}

//! Destroys the root node
template <typename TK, typename TD>
BinarySearchTree<TK,TD>::~BinarySearchTree()		// done
{
    if ( m_ptrRoot != nullptr ) { delete m_ptrRoot; }
}

//! Creates a new node for the tree and assigns the data of that node to the parameter passed in.
/**
    If the tree is empty, the new data goes at the root node.
    Otherwise, we will have to recurse through the tree in order to
    find the correct position for our new data.

    Step-by-step:
    - if root is null...
        - Create a new node via the root pointer. Set its key and data.
        - Increment the node count
    - else...
        - Use the Contains function to see if this key already exists in the tree
            - If this key is already used: Display an error "this key is already taken" to cout.
            - Otherwise, call RecursivePush with the newKey, newData, and the root.

    @param newKey const TK&, the key to index this new item under
    @param newData const TD&, the new data to be added to the tree
    @return <void>
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::Push( const TK& newKey, const TD& newData )
{
	if (m_ptrRoot == nullptr) {
		m_ptrRoot = new Node<TK, TD>;
		m_ptrRoot->key = newKey;
		m_ptrRoot->data = newData;
		m_nodeCount++;
	}
	else
	{
		if (Contains(newKey))
			cout << "this key is already taken" << endl;
		else
			RecursivePush(newKey, newData, m_ptrRoot);
	}
}

//! Deletes the Node that contains the given data, if it exists in the tree.
/**
    Search the tree for a Node that contains the data. This Node will be removed.
    BEFORE you remove it, you need to relocate its children AND
    set the "deleteMe" node's children to nullptr.

    - Create a Node pointer called deleteMe. Use FindNode to find the node to delete via its key.
    - Create a Node pointer called parent. Use the FindParentOfNode with the key to find its parent.
    - Create a boolean called isLeftNode. If the parent's left child is the deleteMe node, set this to true. Otherwise, false.

    - If the deleteMe node is nullptr, then return.
    - If the deleteMe pointer has no children, call DeleteNode_NoChildren
    - If the deleteMe pointer has only a left child, call DeleteNode_LeftChild
    - If the deleteMe pointer has only a right child call DeleteNode_RightChild
    - If the deleteMe pointer has a left AND a right child, call DeleteNode_TwoChildren

    @param data const TK&, the data to be removed from the tree.
    @return <void>
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::Delete( const TK& key )   // done - implement the delete helper functions
{
    // Locate node
    Node<TK, TD>* deleteMe = FindNode( key );

    if ( deleteMe == nullptr )
    {
        cout << "deleteMe is nullptr" << endl << endl;
        return;
    }

    Node<TK, TD>* parent = FindParentOfNode( key );
    bool isLeftNode = ( parent->ptrLeft == deleteMe );

    // Does this node have no children?
    if ( deleteMe->ptrLeft == nullptr && deleteMe->ptrRight == nullptr )
    {
        DeleteNode_NoChildren( deleteMe, parent, isLeftNode );
    }
    // Only has right child
    else if ( deleteMe->ptrLeft == nullptr )
    {
        DeleteNode_RightChild( deleteMe, parent, isLeftNode );
    }
    // Only has left child
    else if ( deleteMe->ptrRight == nullptr )
    {
        DeleteNode_LeftChild( deleteMe, parent, isLeftNode );
    }
    // Has two children
    else
    {
        DeleteNode_TwoChildren( deleteMe, parent, isLeftNode );
    }
}

//! Deletes the given node, which has no children.
/**
    - If deleteMe is the root:              Set the m_ptrRoot to nullptr.
    - Else if deleteMe is the left node:    Set the parent's ptrLeft to nullptr.
    - Else if deleteMe is the right node:   Set the parent's ptrRight to nullptr.

    - Set deleteMe's left ptr to nullptr.
    - Set deleteMe's right ptr to nullptr.
    - Delete deleteMe.
    - Decrement the node count.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::DeleteNode_NoChildren( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode )
{
	if (deleteMe == m_ptrRoot) { m_ptrRoot = nullptr; }
	else if (deleteMe == parent->ptrLeft) { parent->ptrLeft = nullptr; }
	else if (deleteMe == parent->ptrRight) { parent->ptrRight = nullptr; }
	deleteMe->ptrLeft = nullptr;
	deleteMe->ptrRight = nullptr;
	delete deleteMe;
	m_nodeCount--;
}

//! Deletes the given node, which has a left child but no right child.
/**
    - If deleteMe is the root:              Set m_ptrRoot to the deleteMe's ptrLeft.
    - If deleteMe is the left node:         Set the parent's ptrLeft to deleteMe's ptrLeft.
    - If deleteMe is the right node:        Set the parent's ptrRight to deleteMe's ptrLeft.

    - Set deleteMe's left ptr to nullptr.
    - Set deleteMe's right ptr to nullptr.
    - Delete deleteMe.
    - Decrement the node count.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::DeleteNode_LeftChild( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode )
{
	if (deleteMe == m_ptrRoot) { m_ptrRoot = deleteMe->ptrLeft; }
	//if (isLeftNode) { parent->ptrLeft = deleteMe->ptrLeft; }
	//if (!isLeftNode) { parent->ptrRight = deleteMe->ptrLeft; }
	else if (deleteMe == parent->ptrLeft) { parent->ptrLeft = deleteMe->ptrLeft; }
	else if (deleteMe == parent->ptrRight) { parent->ptrRight = deleteMe->ptrLeft; }

	deleteMe->ptrLeft = nullptr;
	deleteMe->ptrRight = nullptr;
	delete deleteMe;
	m_nodeCount--;
}

//! Deletes the given node, which has a right child but no left.
/**
    - If deleteMe is the root:              Set m_ptrRoot to the deleteMe's ptrRight.
    - If deleteMe is the left node:         Set the parent's ptrLeft to deleteMe's ptrRight.
    - If deleteMe is the right node:        Set the parent's ptrRight to deleteMe's ptrRight.

    - Set deleteMe's left ptr to nullptr.
    - Set deleteMe's right ptr to nullptr.
    - Delete deleteMe.
    - Decrement the node count.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::DeleteNode_RightChild( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode )
{
	if (deleteMe == m_ptrRoot) { m_ptrRoot = deleteMe->ptrRight; }
	if (deleteMe == parent->ptrLeft) { parent->ptrLeft = deleteMe->ptrRight; }
	if (deleteMe == parent->ptrRight) { parent->ptrRight = deleteMe->ptrRight; }

	deleteMe->ptrLeft = nullptr;
	deleteMe->ptrRight = nullptr;
	delete deleteMe;
	m_nodeCount--;
}

//! Deletes the given node, which has children to the left and to the right.
/**
    - Create a new Node pointer called tempNode, set it to deleteMe's right child.
    - Create a new Node pointer called successor, set it to deleteMe.
    - Create a new Node pointer called successorParent, set it to deleteMe.

    - while the tempNode is not equal to nullptr...
        - Set successorParent to the successor
        - Set successor to the tempNode
        - Set tempNode to the tempNode's left child.

    - If successor is not equal to deleteMe's right child:
        - Set successorParent's left child to successor's right child.
        - Set successor's right child to deleteMe's right child.

    - If deleteMe is the root:
        Set the root to the successor.

    - Else if deleteMe is the left node:
        - Set deleteMe to the parent's ptrLeft
        - Set the parent's ptrLeft to the successor

    - Else if deleteMe is the right node:
        - Set deleteMe to the parent's ptrRight
        - Set the parent's ptrRight to the successor

    - Set the successor's ptrLeft to deleteMe's ptrLeft.

    - Set deleteMe's left ptr to nullptr.
    - Set deleteMe's right ptr to nullptr.
    - Delete deleteMe.
    - Decrement the node count.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::DeleteNode_TwoChildren( Node<TK, TD>* deleteMe, Node<TK, TD>* parent, bool isLeftNode )
{
//	-Create a new Node pointer called tempNode, set it to deleteMe's right child.
//- Create a new Node pointer called successor, set it to deleteMe.
//- Create a new Node pointer called successorParent, set it to deleteMe.
	Node<TK, TD> *tempNode = new Node<TK, TD>;
	tempNode = deleteMe->ptrRight;
	Node<TK, TD> *successor = new Node<TK, TD>;
	successor = deleteMe;
	Node<TK, TD> *successorParent = new Node<TK, TD>;
	successorParent = deleteMe;

//	-while the tempNode is not equal to nullptr...
//		- Set successorParent to the successor
//		- Set successor to the tempNode
//		- Set tempNode to the tempNode's left child.

	while (tempNode != nullptr) {
		successorParent = successor;
		successor = tempNode;
		tempNode = tempNode->ptrLeft;
	}

//	-If successor is not equal to deleteMe's right child:
//		- Set successorParent's left child to successor's right child.
//		- Set successor's right child to deleteMe's right child.

	if (successor != deleteMe->ptrRight) {
		successorParent->ptrLeft = successor->ptrRight;
		successor->ptrRight = deleteMe->ptrRight;
	}
/*
- If deleteMe is the root:
Set the root to the successor.

- Else if deleteMe is the left node:
- Set deleteMe to the parent's ptrLeft
- Set the parent's ptrLeft to the successor

- Else if deleteMe is the right node:
- Set deleteMe to the parent's ptrRight
- Set the parent's ptrRight to the successor

*/
	if (deleteMe == m_ptrRoot) { m_ptrRoot = successor; }
	else if (deleteMe == parent->ptrLeft) { //(isLeftNode) { // burasina leftNode??? bakmak lazim
		deleteMe = parent->ptrLeft;
		parent->ptrLeft = successor;
	}
	else if (deleteMe == parent->ptrRight) {
		deleteMe = parent->ptrRight;
		parent->ptrRight = successor;
	}

/*
- Set the successor's ptrLeft to deleteMe's ptrLeft.

- Set deleteMe's left ptr to nullptr.
- Set deleteMe's right ptr to nullptr.
- Delete deleteMe.
- Decrement the node count.
*/

	successor->ptrLeft = deleteMe->ptrLeft;

	deleteMe->ptrLeft = nullptr;
	deleteMe->ptrRight = nullptr;
	delete deleteMe;
	m_nodeCount--;

}


//! Searches the tree for the key provided and returns true if found, false if not.
/**
    @return <bool> whether or not the key is found in the tree.
*/
template <typename TK, typename TD>
bool BinarySearchTree<TK,TD>::Contains( const TK& key ) // done
{
    return RecursiveContains( key, m_ptrRoot );
}

//! Recursively searches the tree and returns true if found, and false if not.
/**
    TERMINATING CASE 1: If the ptrCurrent is nullptr, return false.

    TERMINATING CASE 2: If the ptrCurrent's key is equal to the key, return true.

    RECURSIVE CASE:
        Call both RecursiveContains( key, ptrCurrent->ptrLeft ) and RecursiveContains( key, ptrCurrent->ptrRight ).
        If either of these return true, then return true.
*/
template <typename TK, typename TD>
bool BinarySearchTree<TK,TD>::RecursiveContains( const TK& key, Node<TK, TD>* ptrCurrent )
{
	if (ptrCurrent == nullptr) { return false; }
	else if (ptrCurrent->key == key) { return true; }
	else if (key < ptrCurrent->key)
		RecursiveContains(key, ptrCurrent->ptrLeft);
	else
		RecursiveContains(key, ptrCurrent->ptrRight);

    //return false; // temporary placeholder
}

//! Displays the keys of the nodes in the tree, in in-order format.
/**
    This function creates a stringstream and calls the recursive
    GetInOrder function. It will return the keys of the nodes in the tree
    in string format.

    @return <string> The keys of the nodes in the tree, in in-order format, as a string.
*/
template <typename TK, typename TD>
string BinarySearchTree<TK,TD>::GetInOrder()     // done
{
    stringstream stream;
    GetInOrder( m_ptrRoot, stream );
    return stream.str();
}

//! Displays the keys of the nodes in the tree, in pre-order format.
/**
    This function creates a stringstream and calls the recursive
    GetPreOrder function. It will return the keys of the nodes in the tree
    in string format.

    @return <string> The keys of the nodes in the tree, in pre-order format, as a string.
*/
template <typename TK, typename TD>
string BinarySearchTree<TK,TD>::GetPreOrder()     // done
{
    stringstream stream;
    GetPreOrder( m_ptrRoot, stream );
    return stream.str();
}

//! Displays the keys of the nodes in the tree, in post-order format.
/**
    This function creates a stringstream and calls the recursive
    GetPostOrder function. It will return the keys of the nodes in the tree
    in string format.

    @return <string> The keys of the nodes in the tree, in post-order format, as a string.
*/
template <typename TK, typename TD>
string BinarySearchTree<TK,TD>::GetPostOrder()     // done
{
    stringstream stream;
    GetPostOrder( m_ptrRoot, stream );
    return stream.str();
}

//! Returns the largest value in the tree
/**
    Keep in mind that, for any given node, anything to
    the RIGHT is greater than that node.

    @return <TK*> Largest key in the tree, or nullptr if tree is empty
*/
template <typename TK, typename TD>
TK* BinarySearchTree<TK,TD>::GetMaxKey()     // done
{
    return GetMax( m_ptrRoot );
}

//! Returns the smallest value in the tree
/**
    Keep in mind that, for any given node, anything to
    the LEFT is greater than that node.

    @return <TK*> Smallest key in the tree, or nullptr if tree is empty
*/
template <typename TK, typename TD>
TK* BinarySearchTree<TK,TD>::GetMinKey()     // done
{
    return GetMin( m_ptrRoot );
}

//! Returns the amount of nodes in the tree.
/**
    @return <int> the amount of nodes in the tree
*/
template <typename TK, typename TD>
int BinarySearchTree<TK,TD>::GetCount()     // done
{
    return m_nodeCount;
}

//! Returns the height of the entire tree; must be max height.
/**
    @return <int> height of the tree
*/
template <typename TK, typename TD>
int BinarySearchTree<TK,TD>::GetHeight()     // done
{
    if ( m_ptrRoot == nullptr ) { return 0; }
    return GetHeight( m_ptrRoot );
}

//! Returns the data based on a key passed in, or nullptr if not present.
/**
    Search the binary tree for the node that has the given key
    (can use the FindNode function), and returns the data associated
    with that node. If no node is found, return nullptr instead.

    @param key <TK&>    the key of the node we're searching for
    @return <TD*>       data of the node that has the key given
*/
template <typename TK, typename TD>
TD* BinarySearchTree<TK,TD>::GetData( const TK& key )	// done
{
    Node<TK, TD>* node = FindNode( key );
    if ( node == nullptr ) { return nullptr; }
    return &(node->data);
}

//! Returns the Node* that contains the key, or nullptr if data is not in the tree.
/**
    Similar to the Contains function, you will have to traverse the tree to find
    the key. If you find the Node that contains this data, you will return
    the Node*.

    @param data <const TK&>, the key that we are searching for.
    @return <Node<T>*> the Node* that contains the key. Otherwise, nullptr if data is not found.
*/
template <typename TK, typename TD>
Node<TK, TD>* BinarySearchTree<TK,TD>::FindNode( const TK& key )
{
    return RecursiveFindNode( key, m_ptrRoot );
}

template <typename TK, typename TD>
Node<TK, TD>* BinarySearchTree<TK,TD>::RecursiveFindNode( const TK& key, Node<TK, TD>* ptrCurrent )
{
	if (ptrCurrent == nullptr) { return nullptr; }
	else if (ptrCurrent->key == key) { return ptrCurrent; }
	else if (key < ptrCurrent->key)
		RecursiveFindNode(key, ptrCurrent->ptrLeft);
	else
		RecursiveFindNode(key, ptrCurrent->ptrRight);


    //return nullptr; // temporary placeholder
}

//! Returns the PARENT Node* of the Node* that contains the key, or nullptr if data is not in the tree.
/**
    Similar to the FindNode function, you will instead return the PARENT NODE
    of the node that contains the key, rather than the node itself.

    @param data <const TK&>,    the key we are searching for; but going to return the parent of this node.
    @return <Node<TK, TD>*>     the Node* that contains the data. Otherwise, nullptr if key is not found.
*/

template <typename TK, typename TD>
Node<TK, TD>* BinarySearchTree<TK, TD>::FindParentOfNode(const TK& key)
{
	if (m_ptrRoot == nullptr) { return nullptr; } // tree is empty

	Node<TK, TD>* ptrCurrent = m_ptrRoot;
	Node<TK, TD>* ptrPrevious = nullptr;

	while (ptrCurrent->key != key) // stop once we found the node
	{
		ptrPrevious = ptrCurrent;

		// Go left or go right? add code
		if (key < ptrCurrent->key)
		{
			ptrCurrent = ptrCurrent->ptrLeft;
		}
		else
		{
			ptrCurrent = ptrCurrent->ptrRight;
		}

		// Get past end of tree - this node doesn't exist
		if (ptrCurrent == nullptr) { return nullptr; } // can't find node
	}

	return ptrPrevious;
}
// RECURSIVE FUNCTIONS: These will recurse through
// the tree to do the specified operation and
// return the result back to the interface function,
// to return back to the caller.

//! Recurses through the tree and finds the proper location for the new data.
/**
    - If the newKey is less than the ptrCurrent's key then...
        - Check if the left position is available (ptrCurrent->ptrLeft is nullptr?)
        - If the left position is available...
            - Create the new node as ptrCurrent->ptrLeft = newNode<TK,TD>;
            - Set up its key and data
            - Increment the node count
        - Otherwise...
            - Recurse left with RecursivePush( newKey, newData, ptrCurrent->ptrLeft );
        
    - If the newKey is greater than the ptrCurrent's key then...
        - Check if the left position is available (ptrCurrent->ptrRight is nullptr?)
        - If the right position is available...
            - Create the new node as ptrCurrent->ptrRight = newNode<TK,TD>;
            - Set up its key and data
            - Increment the node count
        - Otherwise...
            - Recurse left with RecursivePush( newKey, newData, ptrCurrent->ptrRight );
        

    @param newKey const TK&,            the key to index this new item under
    @param newData const TD&,           the new data to be added to the tree
    @param ptrCurrent Node<TK, TD>*,    the pointer to the current root of a subtree;
        will traverse left or right if newKey is less-than or greater-than, respectively.
    @return <void>
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::RecursivePush( const TK& newKey, const TD& newData, Node<TK, TD>* ptrCurrent )
{
	if (newKey < ptrCurrent->key) {
		if (ptrCurrent->ptrLeft == nullptr) {
			ptrCurrent->ptrLeft = new Node<TK, TD>;
			ptrCurrent->ptrLeft->key = newKey;
			ptrCurrent->ptrLeft->data = newData;
			m_nodeCount++;
		}
		RecursivePush(newKey, newData, ptrCurrent->ptrLeft);
	}

	if (newKey > ptrCurrent->key) {
		if (ptrCurrent->ptrRight == nullptr) {
			ptrCurrent->ptrRight = new Node<TK, TD>;
			ptrCurrent->ptrRight->key = newKey;
			ptrCurrent->ptrRight->data = newData;
			m_nodeCount++;
		}
		RecursivePush(newKey, newData, ptrCurrent->ptrRight);
	}
}

//! Recurses through the tree in IN-ORDER order, writing to the stream.
/**
    In order will display the items in the tree in ascending order.
    From an algorithmic point of view, for whatever node it is on, it will:
        - Display the left node item (recurse GetInOrder on left child)
        - Display the current node item
        - Display the right node item (recurse GetInOrder on right child)

    To write out to the stream, simply use:
    stream << ptrCurrent->key << " ";

    Note that it is expected that you will have a leading space " "
    at the end of the generated string.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::GetInOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
{
    if ( ptrCurrent != nullptr )
    {
		GetInOrder(ptrCurrent->ptrLeft, stream);
		stream << ptrCurrent->key << " ";
		GetInOrder(ptrCurrent->ptrRight, stream);
        // Do stuff
    }
}

//! Recurses through the tree in PRE-ORDER order, writing to the stream.
/**
    In order will display the items in the tree pre-order.
    From an algorithmic point of view, for whatever node it is on, it will:
        - Display the current node item
        - Display the left node item
        - Display the right node item

    Note that it is expected that you will have a leading space " "
    at the end of the generated string.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::GetPreOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
{
    if ( ptrCurrent != nullptr )
    {
		stream << ptrCurrent->key << " ";
		GetPreOrder(ptrCurrent->ptrLeft, stream);
		GetPreOrder(ptrCurrent->ptrRight, stream);
        // Do stuff
    }
}

//! Recurses through the tree in POST-ORDER order, writing to the stream.
/**
    In order will display the items in the tree post-order.
    From an algorithmic point of view, for whatever node it is on, it will:
        - Display the left node item
        - Display the right node item
        - Display the current node item

    Note that it is expected that you will have a leading space " "
    at the end of the generated string.
*/
template <typename TK, typename TD>
void BinarySearchTree<TK,TD>::GetPostOrder( Node<TK, TD>* ptrCurrent, stringstream& stream )
{
    if ( ptrCurrent != nullptr )
    {
		GetPostOrder(ptrCurrent->ptrLeft, stream);
		GetPostOrder(ptrCurrent->ptrRight, stream);
		stream << ptrCurrent->key << " ";
        // Do stuff
    }
}

//! Recurses through the tree, going to the right-child-nodes until the max key is found.
/**
    Items are inserted into a binary search tree in a sorted order.
    This means that larger items always get inserted to the right,
    with the maximum value being the right-most value.
*/
template <typename TK, typename TD>
TK* BinarySearchTree<TK,TD>::GetMax( Node<TK, TD>* ptrCurrent )
{

	if (ptrCurrent == nullptr) { return nullptr; }
	else if (ptrCurrent->ptrRight == nullptr) { return &ptrCurrent->key; }
	else
		return 	GetMax(ptrCurrent->ptrRight);


    //return nullptr; // temporary placeholder
}

//! Recurses through the tree, going to the right-child-nodes until the max key is found.
/**
    Items are inserted into a binary search tree in a sorted order.
    This means that larger items always get inserted to the left,
    with the minimum value being the left-most value.
*/
template <typename TK, typename TD>
TK* BinarySearchTree<TK,TD>::GetMin( Node<TK, TD>* ptrCurrent )
{
	if (ptrCurrent == nullptr) { return nullptr; }
	else if (ptrCurrent->ptrLeft  == nullptr) {return &ptrCurrent->key;}
	else 
		return 	GetMin(ptrCurrent->ptrLeft);

	/*
	while (ptrCurrent->ptrLeft != nullptr)
	{
		GetMin(ptrCurrent->ptrleft);

	}
	return ptrCurrent->ptrLeft;
	*/
	
	//return nullptr; // temporary placeholder
}

//! Get the height of the tree (the longest path from the root to the lowest leaf)
/**
    Get the height of left sub tree, say leftHeight
    Get the height of right sub tree, say rightHeight
    Take the Max(leftHeight, rightHeight) and add 1 for the root and return
    Call recur­sively.
*/
template <typename TK, typename TD>
int BinarySearchTree<TK,TD>::GetHeight( Node<TK, TD>* ptrCurrent )
{
	if (ptrCurrent == nullptr) { return 0; }

	int leftHeight = GetHeight(ptrCurrent->ptrLeft);
	int rightHeight = GetHeight(ptrCurrent->ptrRight);

	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	else 
		return (rightHeight + 1);
}

#endif
