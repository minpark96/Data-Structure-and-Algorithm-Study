#include <iostream>

using namespace std;

/* 
	[해결방안]
	자릿수가 굉장히 커서 오버플로우가 되지 않는 조건에서
	나머지 연산을 계속 수행하는데
	시간제한 때문에 효율적인 연산을 하기 위해서는 제곱의 성질을 이용한다.
	이미 한번 구한 제곱수는 또 연산할 필요가 없다.
	그 해결방법으로 재귀 함수를 사용한다.
	홀수의 제곱을 처리해야 한다.
	또 오버플로우를 방지하려면 나머지 연산의 성질인 분배법칙을 활용해야한다.
*/

#pragma region 최초 풀이 - 정답 참조

typedef long long ll;
ll A, B, C;
ll Go(ll b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll ret;
	cin >> A >> B >> C;
	ret = Go(B);
	cout << ret << "\n";
	return 0;
}

ll Go(ll n)
{
	if (n == 1) return A % C;
	ll ret = Go(n / 2);
	ret = (ret * ret) % C;
	if (n % 2) return (ret * A) % C;
	return ret;
}

#pragma endregion