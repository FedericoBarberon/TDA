#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

matInt multiplicarMatrices(const matInt &A, const matInt &B)
{
    int n = sz(A);
    matInt C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

matInt sumaMatriz(const matInt &A, const matInt &B)
{
    int n = sz(A);
    matInt sum(n, vecInt(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    return sum;
}

matInt potenciaMatriz(const matInt &A, int p)
{
    if (p == 1)
    {
        return A;
    }

    matInt half = potenciaMatriz(A, p / 2);
    matInt res = multiplicarMatrices(half, half);

    if (p % 2 != 0)
    {
        res = multiplicarMatrices(res, A);
    }

    return res;
}

matInt potenciaSum(const matInt &A, int n)
{
    if (n == 1)
    {
        return A;
    }

    matInt half = potenciaMatriz(A, n / 2);
    matInt rec = potenciaSum(A, n / 2);

    return sumaMatriz(rec, multiplicarMatrices(half, rec));
}

int main()
{
    fastio;

    int n = 10;
    matInt mat = {
        {2, 3, 6, 3},
        {1, 4, 7, -1},
        {5, 6, 5, 3},
        {9, 13, -4, 2}};

    auto ans = potenciaSum(mat, n);

    for (auto &row : ans)
    {
        printVec(row);
    }
    return 0;
}