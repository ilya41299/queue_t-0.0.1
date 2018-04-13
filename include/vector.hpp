#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class queue_t
{
private:
	struct node_t
	{
		node_t *next;
		T value;
	};
private:
	node_t * head;
	node_t * tail;
public:
	queue_t();
	T & operator =(queue_t<T> & other);
	queue_t(queue_t & other);
	~queue_t();
	void push(T value);
	T pop();
	node_t* header()
	{
		return head;
	}
	node_t * tailer()
	{
		return tail;
	}
};

template <typename T>
queue_t<T> & queue_t<T>::operator= (queue_t<T> & other)
{
	if (other.head != nullptr) 
	{
		this->~queue_t();
	}
	node_t* node = other.head;
	while (node != nullptr) 
	{
		push(node->value);
		node = node->next;
	}
	return *this;
}

template <typename T>
queue_t<T>::queue_t()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
queue_t<T>::~queue_t()
{
	while (head != nullptr) 
	{
		node_t * node = head;
		head = head->next;
		delete node;
	}
}

template <typename T>
void queue_t<T>::push(T value)
{
	if (head == nullptr)
	{
		head = new node_t;
		head->value = value;
		head->next = nullptr;
		tail = head;
	}
	else
	{
		tail->next = new node_t;
		tail = tail->next;
		tail->value = value;
		tail->next = nullptr;
	}
}

template <typename T>
T queue_t<T>::pop()
{
	if (head == nullptr)
	{
		throw std::logic_error("Error delete element");
	}
	T Deleted_a = head->value;
	node_t* param = head;
	head = head->next;
	delete param;
	return Deleted_a;
}

template <typename T>
queue_t<T>::queue_t(queue_t & other)
{
	node_t* node = other.head;
	while (node != nullptr)
	{
		push(node->value);
		node = node->next;
	}
}
