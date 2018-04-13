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
	}
	node_t * head;
	node_t * tail;
public:
	queue_t();
	~queue_t();
	void push(T value);
	void back();
};

template <typename T>
queue_t<T>::queue_t()
{
	head=nullptr
	tail=nullptr
}

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
	~queue_t();
	void push(T value);
	void pop();
	void del(node_t * head);
};

template <typename T>
queue_t<T>::queue_t()
{
	head = nullptr;
	tail = nullptr;
}


template <typename T>
queue_t<T>::~queue_t()
{
	if (head != nullptr) 
	{
		del(head);
	}
}


template <typename T>
void queue_t<T>::del(node_t* node)
{
	if (node!= nullptr) 
	{
		if (node->next!=nullptr) 
		{
			del(node->next);
		}
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
void queue_t<T>::pop()
{
	if (head == nullptr) 
	{
		throw Error ("Error delete element");
	}
	node_t* param = head;
	head = head->next;
	delete param;
}

template <typename T>
queue_t<T>::~queue_t()
{
	
}


template <typename T>
void queue_t<T>::push(T value)
{
	if(head==nullptr)
	{
		head->value=value;
		head->next=nullptr;
		tail=head;
	}
	else 
	{
		
	}
}

template <typename T>
void queue_t<T>::back()
{
}
