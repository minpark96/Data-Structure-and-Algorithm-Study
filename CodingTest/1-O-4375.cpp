#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	[해결방안]
	한자리씩 증가시키면서 나머지 연산을 했을 때 0이 나와야
	자릿수를 찾을 수 있다.
	시간제한이 있고 오버플로우가 발생하기 때문에
	나머지 연산의 성질을 이용한다.
	분배법칙을 사용해야한다.
	전체를 계산하고 나머지를 구하는거나, 나머지를 구해가면서 연산을 하는 것이나 결과는 동일하다.
*/

#pragma region 최초 풀이 - 정답 참조

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	while (scanf("%d", &n) != EOF)
	{
		long long ret = 1, cnt = 1; // ret: 자릿수, cnt: 합
		while (true)
		{
			if (cnt % n == 0)
			{
				printf("%lld\n", ret);
				break;
			}

			ret++;
			cnt = cnt * 10 + 1;
			cnt %= n;
		}
	}

	return 0;
}

#pragma endregion