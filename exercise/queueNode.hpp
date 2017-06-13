#ifndef QUEUE_NODE_HEADER
#define QUEUE_NODE_HEADER

#include <iostream>

template<typename Type>
class Queue
{
	struct Node
	{
		Type data;
		Node* next;
	};
	Node* front;
	Node* back;

public:
	Queue() : front(nullptr), back(nullptr) {}

public:
	bool isEmpty() const;
	void enqueue(Type const&);
	Type dequeue();
	Type peek() const;

};

template<typename Type>
bool Queue<Type>::isEmpty() const
{
	return !first;
}

template<typename Type>
void Queue<Type>::enqueue(Type const& obj)
{
	Node* add = new Node;
	if (isEmpty())
	{
		front = back = add;
		front->data = obj;
		front->next = nullptr;
	}
	else
	{
		back->next = add;
		back = add;
		back->data = obj;
		back->nullptr;
	}
}

template<typename Type>
Type Queue<Type>::dequeue()
{
	if (isEmpty()) throw std::invalid_argument("No elements!");
	Type temp = first->data;
	Node* remove = first;
	first = first->next;
	if (isEmpty()) back = front;
	delete[] remove;
	return temp;
}

#endif//QUEUE_NODE_HEADER