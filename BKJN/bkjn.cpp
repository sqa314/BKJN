#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i, n;
	int temp;
	vector<int> line;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> temp;
		if (line.empty() || line.back() < temp)
			line.push_back(temp);
		else
			*lower_bound(line.begin(), line.end(), temp) = temp;
	}
	cout << n - line.size();
	return 0;
}