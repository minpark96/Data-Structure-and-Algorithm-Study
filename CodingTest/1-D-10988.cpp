#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#pragma region 최초 풀이
int main()
{
	string str1, str2;
	cin >> str1;
	str2 = str1;
	reverse(str1.begin(), str1.end());

	cout << (str1 == str2);

	return 0;
}
#pragma endregion
