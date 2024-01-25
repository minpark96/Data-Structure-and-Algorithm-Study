#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 최초 풀이
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
*/
#pragma endregion

#pragma region 개선 1 - 조합의 개념을 써서 풀기
/*
	1. 꼭 vector를 사용할 필요는 없을 듯 
	STL sort는 배열을 정렬 할 수 있을까?
	=> 가능. 
	배열의 sort(시작 지점 포인터, 끝나는 지점 포인터)
	vector -> 배열로 수정

	2. 일단 전체 합을 구해놓고 2개만 뽑아서 빼기
	매번 합을 구할 필요가 없음
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
