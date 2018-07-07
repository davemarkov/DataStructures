#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <iostream>
#include <assert.h>

template<typename Type>
class Queue
{
	Type* queue;
	int capacity;
	int front;
	int back;
public:
	Queue() : 
		queue(nullptr), capacity(8), front(0), back(0) 
	{
		createSpace();
	}
	~Queue();

private:
	void createSpace();
	void resize(); // only increase

public:
	bool isFull() const;
	bool isEmpty() const;

	void enqueue(const Type&);
	Type& dequeue();
	Type& peek() const;

};

template<typename Type>
void Queue<Type>::createSpace()
{
	queue = new Type[capacity];
}

template<typename Type>
void Queue<Type>::resize()
{
	Type* temp = new Type[capacity * 2];
	for (int i = front, newPos = 0; i != back; i = (i + 1) % capacity, ++newPos)
		temp[newPos] = queue[i];
	delete[] queue;
	queue = temp;
	front = 0;
	back = capacity - 1;
	capacity *= 2;
}

template<typename Type>
bool Queue<Type>::isFull() const
{
	return ((back + 1) % capacity) == front;
}

template<typename Type>
bool Queue<Type>::isEmpty() const
{
	return front == back;
}

template<typename Type>
void Queue<Type>::enqueue(const Type& obj)
{
	if (isFull()) resize();
	queue[back] = obj;
	back = (back + 1) % capacity;
}

template<typename Type>
Type& Queue<Type>::dequeue()
{
	if(isEmpty()) throw std::invalid_argument("No elements!");

	Type temp = queue[front];
	front = (front + 1) % capacity;
	return temp;
}

template<typename Type>
Type& Queue<Type>::peek() const
{
	if (isEmpty()) throw std::invalid_argument("No elements!");
	return queue[front];
}

template<typename Type>
Queue<Type>::~Queue()
{
	delete[] queue;
}

#endif//QUEUE_HEADER