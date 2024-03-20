#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/*
	빈도 정렬을 하는데 조건1은 빈도, 조건2는 최초 등장이 빠른 순이다.
	처음에는 map을 두개 사용하여 해결하려고 하였으나 정렬에서 막혔다.
	
	빈도를 측정하는 데 조금 비효율적일 수 있으나 조건2가 손쉽게 해결되므로 
	(정렬을 따로 하지 않고 출력하면서 일일히 체크한다.)
	vector를 하나만 사용하여 해결 하였고 출력 과정에서 속도를 높이기 위해서 set을 사용하여 등장 횟수를 제한하였다.

	map 두개를 사용했을 때 하나는 빈도 측정, 하나는 등장 시점을 측정하기 위해 사용하고
	vector에 pair로 빈도와 실제 수를 저장한다.
	vector를 정렬할 때 custom 함수를 사용해서 빈도가 겹칠 때 등장 시점을 비교하는 방식을 사용한다.
*/

#pragma region 최초 풀이

//struct Node
//{
//	int data;
//	int num;
//};
//
//int n, c;
//vector<Node> v;
//set<int> s;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> c;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		bool flag = true;
//		cin >> temp;
//		for (int j = 0; j < v.size(); j++)
//		{
//			if (temp == v[j].data)
//			{
//				v[j].num++;
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//			v.push_back(Node{ temp, 1 });
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		s.insert(v[i].num);
//	}
//
//	for (auto iter = s.rbegin(); iter != s.rend(); iter++)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (*iter == v[i].num)
//			{
//				for (int k = 0; k < *iter; k++)
//					cout << v[i].data << ' ';
//			}
//		}
//	}
//	cout << "\n";
//	return 0;
//}

#pragma endregion

#pragma region 개선

int n, c;
vector<pair<int, int>> v;
map<int, int> m1, m2;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return m2[a.second] < m2[b.second];
	}
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		m1[temp]++;
		if (m2[temp] == 0)
			m2[temp] = i + 1;
	}

	for (auto iter = m1.begin(); iter != m1.end(); iter++)
	{
		v.push_back({ iter->second, iter->first });
	}

	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].first; j++)
			cout << v[i].second << ' ';
	}
	
	cout << "\n";
	return 0;
}

#pragma endregion