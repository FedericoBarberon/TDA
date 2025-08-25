#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

using ll = long long;
using vecInt = vector<int>;

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

int potenciaLog(int a, int b)
{
    if (b == 0)
        return 1;

    int half = potenciaLog(a, b / 2);
    int res = half * half;

    if (b % 2 == 0)
        res *= a;

    return res;
}

// ---------------------------------------------------
// Main
// ---------------------------------------------------
int main()
{
    fastio;

    int a, b;
    cin >> a >> b;
    cout << potenciaLog(a, b) << "\n";
    return 0;
}