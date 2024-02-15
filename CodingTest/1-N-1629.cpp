#include <iostream>

using namespace std;

/* 
	[�ذ���]
	�ڸ����� ������ Ŀ�� �����÷ο찡 ���� �ʴ� ���ǿ���
	������ ������ ��� �����ϴµ�
	�ð����� ������ ȿ������ ������ �ϱ� ���ؼ��� ������ ������ �̿��Ѵ�.
	�̹� �ѹ� ���� �������� �� ������ �ʿ䰡 ����.
	�� �ذ������� ��� �Լ��� ����Ѵ�.
	Ȧ���� ������ ó���ؾ� �Ѵ�.
	�� �����÷ο츦 �����Ϸ��� ������ ������ ������ �й��Ģ�� Ȱ���ؾ��Ѵ�.
*/

#pragma region ���� Ǯ�� - ���� ����

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