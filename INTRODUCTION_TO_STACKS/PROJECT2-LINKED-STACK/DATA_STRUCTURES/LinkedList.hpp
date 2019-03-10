#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
using namespace std;

#include "Node.hpp"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// Return type boolean to work with the unit tests from last time.
	void PushFront(const T& newData) noexcept;
	void PushBack(const T& newData) noexcept;
	void Insert(const T& newData, int atIndex);

	void PopFront() noexcept;
	void PopBack() noexcept;
	void Remove(int atIndex);

	T& GetFront();
	T& GetBack();
	T& Get(const int index);

	T& operator[](const int index);
	void Clear();

	bool IsEmpty() noexcept;
	int Size() noexcept;

private:
	Node<T>* GetAtIndex(int index) noexcept;

	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
	int m_itemCount;
};


template <typename T>
LinkedList<T>::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;
	m_itemCount = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

template <typename T>
void LinkedList<T>::PushFront(const T& newData) noexcept
{
	// Allocating memory
	Node<T>* newNode = new Node<T>;
	newNode->data = newData;

	// List is empty
	if (m_ptrFirst == nullptr)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	// List has at least one item
	else
	{
		m_ptrFirst->ptrPrev = newNode;
		newNode->ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
	}

	m_itemCount++;
}

template <typename T>
void LinkedList<T>::PushBack(const T& newData) noexcept
{
	// Allocating memory
	Node<T>* newNode = new Node<T>;
	newNode->data = newData;

	// Place the node in the list:
	// List is empty
	if (m_ptrLast == nullptr)
	{
		// Point the first & last ptrs to the new node
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}

	// List has at least one item
	else
	{
		// Point the last node's ptrNext to the new node
		m_ptrLast->ptrNext = newNode;
		newNode->ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
	}

	// Increment item count:
	m_itemCount++;
}

template <typename T>
void LinkedList<T>::Insert(const T& newData, int atIndex)
{
	// Invalid index
	if (atIndex < 0 || atIndex > m_itemCount)
	{
		throw out_of_range("Invalid index");
	}

	else if (atIndex == 0)
	{
		PushFront(newData);
	}

	else if (atIndex == m_itemCount)
	{
		PushBack(newData);
	}

	else
	{
		// Get the item that will go before and after
		Node<T>* ptrBefore = GetAtIndex(atIndex - 1);
		Node<T>* ptrAfter = GetAtIndex(atIndex);

		// Create our new node
		Node<T>* newNode = new Node<T>;
		newNode->data = newData;

		// Update pointers between prev item and new item
		ptrBefore->ptrNext = newNode;
		newNode->ptrPrev = ptrBefore;

		ptrAfter->ptrPrev = newNode;
		newNode->ptrNext = ptrAfter;

		m_itemCount++;
	}
}

template <typename T>
void LinkedList<T>::PopFront() noexcept
{
	if (m_ptrFirst == nullptr)
	{
		// List is empty; ignore
		return;
	}

	// there is only one item in the list
	else if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
	}

	// there is more than one item in the list
	else
	{
		// Locate the second item
		Node<T>* ptrSecond = m_ptrFirst->ptrNext;

		// Free the memory for the first item
		delete m_ptrFirst;

		// Set the new first item
		m_ptrFirst = ptrSecond;

		// Make sure first item's ptrPrev points to nullptr
		m_ptrFirst->ptrPrev = nullptr;
	}

	m_itemCount--;
}

template <typename T>
void LinkedList<T>::PopBack() noexcept
{
	if (m_ptrFirst == nullptr)
	{
		// List is empty; ignore
		return;
	}

	// there is only one item in the list
	else if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
	}

	// there is more than one item in the list
	else
	{
		// Locate the second-to-last item
		Node<T>* ptrSecondToLast = m_ptrLast->ptrPrev;

		// Free the memory for the last item
		delete m_ptrLast;

		// Set the new last item
		m_ptrLast = ptrSecondToLast;

		// Set the last item's ptrNext to nullptr
		m_ptrLast->ptrNext = nullptr;
	}

	m_itemCount--;
}

template <typename T>
void LinkedList<T>::Remove(int atIndex)
{
	if (atIndex < 0 || atIndex > m_itemCount)
	{
		throw out_of_range("Invalid index");
	}

	else if (atIndex == 0)
	{
		PopFront();
	}

	else if (atIndex == m_itemCount)
	{
		PopBack();
	}

	else
	{
		Node<T>* ptrBefore = GetAtIndex(atIndex - 1);
		Node<T>* ptrDeleteMe = GetAtIndex(atIndex);
		Node<T>* ptrAfter = GetAtIndex(atIndex + 1);

		delete ptrDeleteMe;

		ptrBefore->ptrNext = ptrAfter;
		ptrAfter->ptrPrev = ptrBefore;

		m_itemCount--;
	}
}

template <typename T>
T& LinkedList<T>::GetFront()
{
	if (m_ptrFirst == nullptr)
	{
		throw out_of_range("Can't GetFront() for empty list!");
	}

	return m_ptrFirst->data;
}

template <typename T>
T& LinkedList<T>::GetBack()
{
	if (m_ptrLast == nullptr)
	{
		throw out_of_range("Can't GetBack() for empty list!");
	}

	return m_ptrLast->data;
}

template <typename T>
Node<T>* LinkedList<T>::GetAtIndex(int index) noexcept
{
	if (m_ptrFirst == nullptr)
	{
		// List is empty
		return nullptr;
	}
	else if (index < 0 || index > m_itemCount)
	{
		// Invalid index
		return nullptr;
	}

	Node<T>* ptrCurrent = m_ptrFirst;
	for (int i = 0; i < index; i++)
	{
		ptrCurrent = ptrCurrent->ptrNext;
	}

	// ptrCurrent should be at the index-position item
	return ptrCurrent;
}

template <typename T>
T& LinkedList<T>::Get(const int index)
{
	// Invalid index
	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Invalid index");
	}

	// Traverse the list
	Node<T>* ptrCurrent = m_ptrFirst;
	for (int i = 0; i < index; i++)
	{
		ptrCurrent = ptrCurrent->ptrNext;
	}

	return ptrCurrent->data;
}

template <typename T>
T& LinkedList<T>::operator[](const int index)
{
	return Get(index);
}

template <typename T>
void LinkedList<T>::Clear()
{
	while (m_ptrFirst != nullptr)
	{
		PopFront();
	}
}

template <typename T>

bool LinkedList<T>::IsEmpty() noexcept
{
	return (m_ptrFirst == nullptr);
}

template <typename T>
int LinkedList<T>::Size() noexcept
{
	return m_itemCount;
}



#endif
