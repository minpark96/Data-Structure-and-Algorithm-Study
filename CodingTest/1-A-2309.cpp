#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	[�ذ���]
	���� �Ǵ� �������� Ǯ��� �ϴ� ����
	������ �Ű澴�ٸ� ���� Ǫ�� �ӵ��� ������ �� �����ϱ� ����.
*/

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

#pragma region ���� 2 - ����Լ� �̿��� �������� Ǯ��
/*
	r���� Ŀ�� ��ø for������ �ϱ⿡�� �ʹ� for���� ��������
	����Լ��� �̿��ϸ� �ڵ尡 ����������!

	�׷��� 
	1. �������� ������� ������ ���ڰ� �ʹ� ������
	2. vector�� ��������ʰ� �ϴ� ����� �ִ���?
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

#pragma region ���� 3 - ����(next_permutation)�� Ǯ��
/*
	������ ����ص� �������.
	������ ������ �ϴ� ã���� �����̱� ������ �ߺ��� �Ű澲�� �ʾƵ� ��
	next_permutation���� ���� ã�� ����� �� �� ������ �ʿ� �����µ�
	����� �غ��� next_permutation�� ���� ����� ���ʿ� 7���� ���� �̾��� ���� �������� ������ �� �����ΰɷ� Ȯ�� ��
	�׷��� �� �������� ���µ� �ߺ��� ��츦 ��� ã���Ƿ� �����ϸ� �������� Ǫ�°� �� ���ٰ� �����Ѵ�.
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

#pragma region ���� 4 - ����(���)�� Ǯ��
/*
	��� �Լ��� ���� ���� ����
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


// r=7�϶� �ξ� �����ɸ�

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