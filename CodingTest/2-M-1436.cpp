#include <iostream>
#include<string>
using namespace std;

/*
	�����ϰ� Ǫ�� ����
	i = 666 ���� i++ ���ѷ��� ���鼭(���������� ��) stringȭ �ϰ� �ű⼭ "666"�� ã����
	n-- �ؼ� n�� 0�� �Ǹ� Ż��
	���� ��Ģ ã�����ٰ� �ٸ� ����� ���ø��� ���ؼ� ������ ����� ã�Ƴ��� ���ߴ�. 
*/

#pragma region ���� Ǯ�� - ���� ����

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