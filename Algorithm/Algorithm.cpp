#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Stack (LIFO Last-In-First-Out 후입선출)

// [1][2][3][4] << 밀어넣음
// 되돌리기 (Ctrl+Z)

template<typename T, typename Container = vector<T>>
class Stack
{
public:

	void push(const T& value)
	{
		_container.push_back(value);
	}

	T pop()
	{
		T ret = _data[_size - 1];
		_size--;
		return ret;
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	// 컨테이너를 바꿔도 가능 STL 인터페이스 통일의 장점
	//vector<T> _container;
	//list<T> _container;
	Container _container;
};

int main()
{
	Stack<int> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 비었나?
	while (s.empty() == false)
	{
		// 최상위 원소
		int data = s.top();
		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	int size = s.size();
}
