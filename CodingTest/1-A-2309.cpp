#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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
