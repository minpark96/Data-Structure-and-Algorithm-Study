#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	[�ذ���]
	���ڸ��� ������Ű�鼭 ������ ������ ���� �� 0�� ���;�
	�ڸ����� ã�� �� �ִ�.
	�ð������� �ְ� �����÷ο찡 �߻��ϱ� ������
	������ ������ ������ �̿��Ѵ�.
	�й��Ģ�� ����ؾ��Ѵ�.
	��ü�� ����ϰ� �������� ���ϴ°ų�, �������� ���ذ��鼭 ������ �ϴ� ���̳� ����� �����ϴ�.
*/

#pragma region ���� Ǯ�� - ���� ����

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	while (scanf("%d", &n) != EOF)
	{
		long long ret = 1, cnt = 1; // ret: �ڸ���, cnt: ��
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