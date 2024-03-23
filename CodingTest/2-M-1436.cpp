#include <iostream>
#include<string>
using namespace std;

/*
	무식하게 푸는 문제
	i = 666 부터 i++ 무한루프 돌면서(오름차순이 됨) string화 하고 거기서 "666"을 찾으면
	n-- 해서 n이 0이 되면 탈출
	뭐라도 규칙 찾으려다가 다른 방법을 떠올리질 못해서 무식한 방법을 찾아내지 못했다. 
*/

#pragma region 최초 풀이 - 정답 참조

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int i = 666;
	while (true)
	{
		if (to_string(i).find("666") != string::npos) n--;
		if (n == 0) break;
		i++;
	}

	printf("%d\n", i);

	return 0;
}

#pragma endregion