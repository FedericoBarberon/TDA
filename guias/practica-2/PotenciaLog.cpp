#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

int potenciaLog(int a, int b)
{
    if (b == 0)
        return 1;

    int half = potenciaLog(a, b / 2);
    int res = half * half;

    if (b % 2 != 0)
        res *= a;

    return res;
}

int main()
{
    fastio;

    int a, b;
    cin >> a >> b;
    cout << potenciaLog(a, b) << "\n";
    return 0;
}