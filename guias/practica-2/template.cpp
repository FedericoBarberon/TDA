#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int divideConquer(vecInt &arr) { return 0; }

int main()
{
    fastio;

    int n;
    cin >> n;
    vecInt arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto ans = divideConquer(arr);

    cout << ans << "\n";
    return 0;
}
