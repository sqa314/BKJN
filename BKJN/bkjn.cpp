#include <iostream>

using namespace std;

int p[10] = { 1,2,4,8,16,32,64,128,256,512 };

long long int dp[2][10][1024];

int main()
{
	int a;
	int i, j, k;
	int n;
	int temp;
	long long int answer = 0;
	cin >> n;
	for (i = 0; i < 10; ++i)
		dp[0][i][p[i]] = 1;
	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < 10; ++j)
			for (k = 0; k < 1024; ++k)
			{
				if (j != 9)
					temp = (k % p[j + 1]) / p[j];
				else
					temp = k / p[j];
				if (temp && j - 1 != -1)
					dp[1][j][k] += dp[0][j - 1][k];
				if (temp && j + 1 != 10)
					dp[1][j][k] += dp[0][j + 1][k];
				if (!temp && j - 1 != -1)
					dp[1][j][k + p[j]] += dp[0][j - 1][k];
				if (!temp && j + 1 != 10)
					dp[1][j][k + p[j]] += dp[0][j + 1][k];
			}
		for (j = 0; j < 10; ++j)
			for (k = 0; k < 1024; ++k)
			{
				dp[0][j][k] = dp[1][j][k] % 1000000000;
				dp[1][j][k] = 0;
			}
	}
	for (i = 1; i < 10; ++i)
		answer = (answer + dp[0][i][1023]) % 1000000000;
	cout << answer;
	return 0;
}