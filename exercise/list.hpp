#ifndef BOX_LIST_HEADER
#define BOX_LIST_HEADER

template<class T>
class List
{
	struct Box
	{
		T data;
		Box *next, *prev;
	};
	Box* head;
	int size;
public:
	List() :head(nullptr), size(0) {}
	

	class Iterator
	{
	public:
		Box* mPtr;
		Iterator() : mPtr(nullptr) {}
		Iterator(Box* ptr) : mPtr(ptr) {}
		Iterator operator++(int);
		T* operator->();
		T& operator*();
		bool operator==(const Iterator&);
	};

	T& front();
	T& back();
	void pushFront(const T&);
	void pushBack(const T&);
	void insertAfter(Iterator it, const T&);
	void erase(Iterator it);
	void splice(Iterator dest, Iterator from, Iterator to);
	void print();

	Iterator begin();
};

template<class T>
T& List<T>::front()
{
	return head->data;
}

template<class T>
T& List<T>::back()
{
	return head->prev->data;
}

template<class T>
void List<T>::pushBack(const T& obj)
{
	Box* add = new Box;
	if (!head)
	{
		head = add;
		head->next = head->prev = head;
	}
	else
	{
		add->next = head;
		add->prev = head->prev;
		head->prev->next = add;
		head->prev = add;
	}
	size++;
	add->data = obj;
}

template<class T>
void List<T>::pushFront(const T& obj)
{
	pushBack(obj);
	head = head->prev;
}

template<class T>
void List<T>::insertAfter(Iterator it, const T& obj)
{	
	Box* add = new Box;
	add->data = obj;
	
	if (!it.mPtr)
	{
		add->next = it.mPtr->next;
		add->prev = it.mPtr;
		it.mPtr->next->prev = add;
		it.mPtr->next = add;
	}
	size++;
}

template<class T>
void List<T>::erase(Iterator it)
{
	it.mPtr->next->prev = it.mPtr->prev;
	it.mPtr->prev->next = it.mPtr->next;
	delete[] it.mPtr;
	size--;
	if (size == 0) head = nullptr;
}

template<class T>
void List<T>::splice(Iterator dest, Iterator from, Iterator to)
{
	for (--to; from != to; --to)
	{
		insertAfter(dest, to->data);
	}
	insertAfter(dest, from->data);
	
	/*
	for (--to; from != to; from++, dest++)
	{
		insertAfter(dest, from->data);
	}
	insertAfter(dest, from->data);
	*/
}

template<class T>
void List<T>::print()
{
	Iterator p(head);
	for (; p.mPtr != head->prev; p++)
	{
		std::cout << p.mPtr->data;
	}
	std::cout << p.mPtr->data << "\n";
}

//Iterator
template<class T>
typename List<T>::Iterator List<T>::begin() 
{ 
	return Iterator(head);
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	List<T>::Iterator it = *this;
	mPtr = mPtr->next;
	return it;
}

template<class T>
T* List<T>::Iterator:: operator->()
{
	return &mPtr->data;
}

template<class T>
T& List<T>::Iterator::operator*()
{
	return mPtr->data;
}

template<class T>
bool List<T>::Iterator::operator==(const Iterator& it)
{
	return mPtr == it.mPtr;
}

#endif//BOX_LIST_HEADER