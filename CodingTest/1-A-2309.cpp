#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region ���� Ǯ��
/*
void Solution(vector<int>& input, vector<int>& output);

int main()
{
	const int size = 9;

	vector<int> input(size);
	vector<int> output;

	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	// 9�� �߿� 2�� �̱� -> ������ 7���� ���ؼ� 100���� Ȯ��
	
	Solution(input, output);

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}

	return 0;
}

void Solution(vector<int>& input, vector<int>& output)
{
	const int sumHeight = 100;
	// 2�� ���� �̱�
	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int j = i + 1; j < input.size(); j++)
		{
			// 2�� ���� 7�� ���� ���ϱ�
			int sum = 0;
			for (int k = 0; k < input.size(); k++)
			{
				if (k != i && k != j)
					sum += input[k];
			}

			// 100�� �´��� Ȯ��
			if (sum == sumHeight)
			{
				// ������? output�� �ְ� �ߴ�
				for (int l = 0; l < input.size(); l++)
				{
					if (l != i && l != j)
						output.push_back(input[l]);
				}
				return;
			}
		}
	}
}
*/
#pragma endregion

#pragma region ���� 1 - ������ ������ �Ἥ Ǯ��
/*
	1. �� vector�� ����� �ʿ�� ���� �� 
	STL sort�� �迭�� ���� �� �� ������?
	=> ����. 
	�迭�� sort(���� ���� ������, ������ ���� ������)
	vector -> �迭�� ����

	2. �ϴ� ��ü ���� ���س��� 2���� �̾Ƽ� ����
	�Ź� ���� ���� �ʿ䰡 ����
*/
void Solve(int* ary, const int size, const int sum);

int main()
{
	const int size = 9;

	int input[size];
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
		sum += input[i];
	}

	sort(input, input + size);

	Solve(input, size, sum);

	return 0;
}

void Solve(int* ary, const int size, const int sum)
{
	const int target = 100;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sum - ary[i] - ary[j] == target)
			{
				for (int k = 0; k < size; k++)
				{
					if (k == i || k == j) continue;

					cout << ary[k] << "\n";
				}
				return;
			}
		}
	}
}

#pragma endregion
