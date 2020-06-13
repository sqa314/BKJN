#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[10000];
int B[10000];
vector<int> C(10000);

int main()
{
	int i, j;
	int sum = 0;
	int n, m;
	int up;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &B[i]);
		sum += B[i];
	}
	for (i = 0; i < n; ++i)
		for (j = sum; j - B[i] >= 0; --j)
			C[j] = max(C[j], C[j - B[i]] + A[i]);
	for (i = 0; i <= sum; ++i)
		if (m <= C[i])
		{
			printf("%d", i);
			break;
		}
	return 0;
}