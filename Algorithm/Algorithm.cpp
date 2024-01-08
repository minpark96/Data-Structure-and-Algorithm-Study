#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

private:
	Node*	_prev;
	Node*	_next;
	T		_data;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{

	}

	void pop_back()
	{

	}

private:
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;
	}

public:




private:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;
};

int main()
{
	list<int> li;

	list<int>::iterator eraseIt;
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}
}
