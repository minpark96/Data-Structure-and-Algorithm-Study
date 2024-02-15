#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
	[해결방안]
	회문의 가장 간단한 해결방법은 뒤집어서 같은지 비교하면 된다.
*/

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
