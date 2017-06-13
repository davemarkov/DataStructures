#ifndef LINKED_QUEUE_REVERSED_HEADER
#define LINKED_QUEUE_REVERSED_HEADER


template<typename T>
class LinkedQueueReverse
{
	struct Node
	{
		T data;
		Node* prev;
	};
	Node* begin;
	Node* end;

public:
	LinkedQueueReverse() : begin(nullptr), end(nullptr) {}

public:
	bool isEmpty();
	void enqueue(const T&);
	void dequeue();
	T& peek();
	void erase();
	
};

template<typename T>
bool LinkedQueueReverse<T>::isEmpty()
{
	return !begin;
}

template<typename T>
void LinkedQueueReverse<T>::enqueue(const T& obj)
{
	Node* newElem = new Node; 
	newElem->data = obj;
	if (!begin)
	{
		newElem->data = obj;
		begin = newElem;
		end = begin;
		begin->prev = begin;
		return;
	}
	newElem->prev = begin;
	end->prev = newElem;
	end = newElem;
}

template<typename T>
void LinkedQueueReverse<T>::dequeue()
{
	end->prev = begin->prev;
	delete[] begin;
	begin = end->prev;
}

template<typename T>
T& LinkedQueueReverse<T>::peek()
{
	return begin->data;
}

template<typename T>
void LinkedQueueReverse<T>::erase()
{
	while (!isEmpty())
		dequeue();
}



#endif//LINKED_QUEUE_REVERSED_HEADER