#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i, j;
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> mars(n, vector<int>(m));
	vector<vector<int>> dp(2, vector<int>(m));
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			scanf("%d", &mars[i][j]);
	for (i = 1; i < m; ++i)
		mars[0][i] += mars[0][i - 1];
	for (i = 1; i < n; ++i)
	{
		dp[0][0] = mars[i-1][0]+ mars[i][0];
		dp[1][m - 1] = mars[i - 1][m - 1] + mars[i][m - 1];
		for (j = 1; j < m; ++j)
		{
			dp[0][j] = max<int>(dp[0][j - 1], mars[i - 1][j]) + mars[i][j];
			dp[1][m - 1 - j] = max<int>(dp[1][m - 1 - j + 1], mars[i - 1][m - 1 - j]) + mars[i][m - 1 - j];
		}
		for (j = 0; j < m; ++j)
			mars[i][j] = max<int>(dp[0][j], dp[1][j]);
	}
	printf("%d", mars[n - 1][m - 1]);
	return 0;
}