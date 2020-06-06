#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][100001];
int w[101];
int v[101];
int main()
{
	int i, j;
	int N, W;
	cin >> N >> W;
	for (i = 1; i <= N; ++i)
		cin >> w[i] >> v[i];
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= W; ++j)
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
	cout << dp[N][W];
	return 0;
}