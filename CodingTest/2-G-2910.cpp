#include <iostream>
#include <vector>
#include <set>
using namespace std;

#pragma region 최초 풀이

struct Node
{
	int data;
	int num;
};

int n, c;
vector<Node> v;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int temp;
		bool flag = true;
		cin >> temp;
		for (int j = 0; j < v.size(); j++)
		{
			if (temp == v[j].data)
			{
				v[j].num++;
				flag = false;
				break;
			}
		}
		if (flag)
			v.push_back(Node{ temp, 1 });
	}

	for (int i = 0; i < v.size(); i++)
	{
		s.insert(v[i].num);
	}

	for (auto iter = s.rbegin(); iter != s.rend(); iter++)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (*iter == v[i].num)
			{
				for (int k = 0; k < *iter; k++)
					cout << v[i].data << ' ';
			}
		}
	}
	cout << "\n";
	return 0;
}

#pragma endregion