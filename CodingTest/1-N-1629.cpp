#include <iostream>
#include <math.h>

using namespace std;

#pragma region Çª´ÂÁß

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unsigned long long a, b, c, ret;
	cin >> a >> b >> c;

	ret = a % c;
	for (int i = 1; i < b; i++)
	{
		ret *= a % c;
		ret %= c;
	}

	// a^b % c
	
	//a^b/2 * a^b/2


	cout << ret << "\n";

	return 0;
}

#pragma endregion