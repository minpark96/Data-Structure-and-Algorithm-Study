#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	[해결방안]
	순열 또는 조합으로 풀어야 하는 문제
	성능을 신경쓴다면 조합 푸는 속도는 순열이 더 생각하기 쉽다.
*/

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
//void Solve(int* ary, const int size, const int sum);
//
//int main()
//{
//	const int size = 9;
//
//	int input[size];
//	int sum = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		cin >> input[i];
//		sum += input[i];
//	}
//
//	sort(input, input + size);
//
//	Solve(input, size, sum);
//
//	return 0;
//}
//
//void Solve(int* ary, const int size, const int sum)
//{
//	const int target = 100;
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (sum - ary[i] - ary[j] == target)
//			{
//				for (int k = 0; k < size; k++)
//				{
//					if (k == i || k == j) continue;
//
//					cout << ary[k] << "\n";
//				}
//				return;
//			}
//		}
//	}
//}

#pragma endregion

#pragma region 개선 2 - 재귀함수 이용한 조합으로 풀기
/*
	r값이 커져 중첩 for문으로 하기에는 너무 for문이 많아지면
	재귀함수를 이용하면 코드가 간결해진다!

	그러나 
	1. 전역으로 사용하지 않으면 인자가 너무 많아짐
	2. vector를 사용하지않고 하는 방법이 있는지?
*/

//void Combi(int start, vector<int> ans);
//
//const int n = 9;
//const int r = 7;
//const int target = 100;
//vector<int> input(n);
//bool isFound = false;
//
//int main()
//{
//	vector<int> ans;
//	int sum = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> input[i];
//		sum += input[i];
//	}
//
//	sort(input.begin(), input.end());
//
//	Combi(0, ans);
//
//	return 0;
//}
//
//void Combi(int start, vector<int> ans)
//{
//	if (ans.size() == r)
//	{
//		int sum = 0;
//		for (int i : ans)
//		{
//			sum += input[i];
//		}
//
//		if (sum == target)
//		{
//			isFound = true;
//			for (int j : ans)
//			{
//				cout << input[j] << "\n";
//			}
//		}
//		return;
//	}
//
//	for (int i = start; i < n; i++)
//	{
//		ans.push_back(i);
//		Combi(i + 1, ans);
//		if (isFound)
//			return;
//		ans.pop_back();
//	}
//}

#pragma endregion

#pragma region 개선 3 - 순열(next_permutation)로 풀기
/*
	순열을 사용해도 상관없음.
	문제의 조건이 일단 찾으면 종료이기 때문에 중복을 신경쓰지 않아도 됨
	next_permutation으로 수를 찾고 출력을 할 때 정렬이 필요 없었는데
	디버깅 해보니 next_permutation의 동작 방식이 최초에 7가지 수를 뽑았을 때는 오름차순 정렬이 된 상태인걸로 확인 됨
	그러나 그 과정까지 가는데 중복된 경우를 몇가지 찾으므로 가능하면 조합으로 푸는게 더 낫다고 생각한다.
*/
//void Print();
//const int n = 9;
//const int r = 2;
//const int target = 100;
//vector<int> input(n);
//int main()
//{
//	vector<int> ans;
//	int sum = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> input[i];
//		sum += input[i];
//	}
//
//	sort(input.begin(), input.end());
//	
//	do
//	{
//		Print();
//		int tmp = sum;
//		for (int i = 0; i < r; i++)
//		{
//			tmp -= input[n - 1 - i];
//		}
//
//		if (tmp == target)
//		{
//			for (int j = 0; j < n - r; j++)
//			{
//				cout << input[j] << "\n";
//			}
//			break;
//		}
//	} while(next_permutation(input.begin(), input.end()));
//
//	return 0;
//}
//
//void Print()
//{
//	for (int i : input)
//	{
//		cout << i << " ";
//	}
//	cout << "\n";
//}

#pragma endregion

#pragma region 개선 4 - 순열(재귀)로 풀기
/*
	재귀 함수로 순열 구현 연습
*/
void Print();
void Solve(int r);
void MakePermutation(int n, int r, int depth);

const int target = 100;
int sum = 0;
vector<int> input;

int main()
{
	vector<int> ans;

	const int n = 9;
	const int r = 2;
	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		sum += input[i];
	}

	MakePermutation(n, r, 0);

	return 0;
}

void MakePermutation(int n, int r, int depth)
{
	if (r == depth)
	{
		Print();
		Solve(r);
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(input[i], input[depth]);
		MakePermutation(n, r, depth + 1);
		swap(input[i], input[depth]);
	}
}

void Solve(int r)
{
	int tmp = sum;
	for (int i = 0; i < r; i++)
	{
		tmp -= input[i];
	}
	if (tmp == target)
	{
		sort(input.begin() + r, input.end());
		for (int i = r; i < input.size(); i++)
		{
			cout << input[i] << "\n";
		}
		exit(0);
	}
}

void Print()
{
	for (int i : input)
	{
		cout << i << " ";
	}
	cout << "\n";
}


// r=7일때 훨씬 오래걸림

//void Print();
//void Solve(int n, int r);
//void MakePermutation(int n, int r, int depth);
//
//const int target = 100;
//int sum = 0;
//vector<int> input;
//
//int main()
//{
//	vector<int> ans;
//
//	const int n = 9;
//	const int r = 7;
//	input.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> input[i];
//		sum += input[i];
//	}
//
//	MakePermutation(n, r, 0);
//
//	return 0;
//}
//
//void MakePermutation(int n, int r, int depth)
//{
//	if (r == depth) {
//		Print();
//		Solve(n, r);
//		return;
//	}
//	for (int i = depth; i < n; i++) {
//		swap(input[i], input[depth]);
//		MakePermutation(n, r, depth + 1);
//		swap(input[i], input[depth]);
//	}
//}
//
//void Solve(int n, int r)
//{
//	int tmp = sum;
//	for (int i = 0; i < n - r; i++)
//	{
//		tmp -= input[i];
//	}
//	if (tmp == target)
//	{
//		sort(input.begin() + n - r, input.end());
//		for (int i = n - r; i < n; i++)
//		{
//			cout << input[i] << "\n";
//		}
//		exit(0);
//	}
//}
//
//void Print()
//{
//	for (int i : input)
//	{
//		cout << i << " ";
//	}
//	cout << "\n";
//}

#pragma endregion