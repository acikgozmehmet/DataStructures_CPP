#ifndef _NODE_HPP
#define _NODE_HPP

//! The nodes in the array
template <typename TK, typename TD>
struct Node
{
    //! The Node's identifier key
    TK key;
    //! The data stored in the Node
    TD data;
    //! A flag for whether the Node is in use
    bool hasData;

    //! Initializes the Node by setting hasData to false.
    Node() { hasData = false; }
};

#endif
