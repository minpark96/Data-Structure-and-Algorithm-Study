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

	// 9개 중에 2개 뽑기 -> 나머지 7개를 합해서 100인지 확인
	
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
	// 2개 숫자 뽑기
	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int j = i + 1; j < input.size(); j++)
		{
			// 2개 제외 7개 숫자 더하기
			int sum = 0;
			for (int k = 0; k < input.size(); k++)
			{
				if (k != i && k != j)
					sum += input[k];
			}

			// 100이 맞는지 확인
			if (sum == sumHeight)
			{
				// 맞으면? output에 넣고 중단
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
