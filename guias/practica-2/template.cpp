#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

using ll = long long;
using vecInt = vector<int>;
using matInt = vector<vecInt>;

const int INF = 1e9;
const ll LINF = 1e18;

// ---------------------------------------------------
// Funciones auxiliares
// ---------------------------------------------------
template <typename T>
void printVec(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << "\n";
}

template <typename T>
T divideConquer(vector<T> &arr) {}

// ---------------------------------------------------
// Main
// ---------------------------------------------------
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