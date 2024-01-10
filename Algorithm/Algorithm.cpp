#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Quque (FIFO First-In-First-Out 선입선출)

// front << [1][2][3][4] << rear(back)
// 대기열

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}


	void push(const T& value)
	{
		// TODO : 다 찼는지 체크
		if (_size == _container.size())
		{
			// 증설 작업
			int newSize = max(1, _size * 2); // 처음에 0이니깐
			vector<T> newData;
			newData.resize(newSize);
			
			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size(); // back을 다시 유효 범위로 설정
		_size++; // 데이터의 개수
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container; // 순환 구조 original은 deque

	int _front = 0;
	int _back = 0;
	int _size = 0;
};

int main()
{
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
}	
