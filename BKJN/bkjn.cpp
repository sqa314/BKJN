#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int segTree[1000];

int refresh(int a)
{
    if (a == 1)
        return segTree[1];
    segTree[a / 2] = max<int>(segTree[a], segTree[(-a % 2) * 2 + 1]);
    return refresh(a / 2);

}
int main()
{
    int i, j;
    int n;
    int temp;
    int m = 0;
    cin >> n;
    vector<pair<int, int> > line;
    line.resize(n);
    for (i = 0; i < n; ++i)
        cin >> line[i].first >> line[i].second;
    sort(line.begin(), line.end());
    for (i = 0; i < n; ++i)
    {
        for (temp = 1, j = 511; j < 511 + line[i].second; ++j)
            if (segTree[j] == temp)
                ++temp;
        segTree[j] = temp;
        m = refresh(j);
    }
    cout << n - m;
    return 0;
}