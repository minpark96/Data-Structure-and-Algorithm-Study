#include <iostream>
#include <string>
using namespace std;

#pragma region 최초 풀이

int h, w, t, a[104][104];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	
	for (int i = 0; i < h; i++)
	{
		bool flag = false;
		string temp;
		cin >> temp;
		for (int j = 0; j < w; j++)
		{
			if (temp[j] == 'c')
			{
				a[i][j] = 0;
				t = 0;
				flag = true;
			}
			else if (flag)
			{
				t++;
				a[i][j] = t;
			}
			else
			{
				a[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}

#pragma endregion