#include <iostream>
#include <string>
using namespace std;

#pragma region 최초 풀이

//int winner, pMin, pSec, cMin, cSec;
//int retMin[3], retSec[3], score[3];
//
//void nba()
//{
//	if (score[1] > score[2])
//		winner = 1;
//	else if (score[1] < score[2])
//		winner = 2;
//	else
//		winner = 0;
//
//	if (winner)
//	{
//		int vMin = cMin - pMin;
//		int vSec = cSec - pSec;
//
//		if (vSec < 0)
//		{
//			vSec += 60;
//			vMin -= 1;
//		}
//
//		retMin[winner] += vMin;
//		retSec[winner] += vSec;
//		if (retSec[winner] > 59)
//		{
//			retSec[winner] -= 60;
//			retMin[winner] += 1;
//		}
//	}
//}
//
//int n;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	int team;
//
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> team;
//		cin >> s;
//		cMin = stoi(s.substr(0, 2));
//		cSec = stoi(s.substr(3, 2));
//
//		nba();
//
//		score[team]++;
//		pMin = cMin;
//		pSec = cSec;
//	}
//	cMin = 48;
//	cSec = 0;
//	nba();
//
//	for (int i = 1; i < 3; i++)
//	{
//		if (retMin[i] < 10)
//			cout << "0" << retMin[i];
//		else
//			cout << retMin[i];
//		cout << ":";
//		if (retSec[i] < 10)
//			cout << "0" << retSec[i];
//		else
//			cout << retSec[i];
//		cout << "\n";
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 개선

int winner, pSec, cMin, cSec;
int retSec[3], score[3];

void nba()
{
	if (score[1] > score[2])
		winner = 1;
	else if (score[1] < score[2])
		winner = 2;
	else
		winner = 0;

	if (winner)
	{
		int vSec = cSec - pSec;
		retSec[winner] += vSec;
	}
}

int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int team;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> team;
		cin >> s;
		cMin = stoi(s.substr(0, 2));
		cSec = stoi(s.substr(3, 2));
		cSec += (cMin * 60);
		nba();
		score[team]++;
		pSec = cSec;
	}
	cSec = 48 * 60;
	nba();

	for (int i = 1; i < 3; i++)
	{
		if (retSec[i] / 60 < 10)
			cout << "0" << retSec[i] / 60;
		else
			cout << retSec[i] / 60;
		cout << ":";
		if (retSec[i] % 60 < 10)
			cout << "0" << retSec[i] % 60;
		else
			cout << retSec[i] % 60;
		cout << "\n";
	}

	return 0;
}

#pragma endregion