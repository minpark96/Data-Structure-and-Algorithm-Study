#include <iostream>
#include <string>

using namespace std;

#pragma region ����Ǯ��
int main()
{
	string input;
	int alpha[26] = { 0, };

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		char ch = input[i];

		ch -= 'a';
		alpha[ch]++;
	}

	for (int j = 0; j < 26; j++)
	{
		cout << alpha[j] << " ";
	}

	return 0;
}
#pragma endregion