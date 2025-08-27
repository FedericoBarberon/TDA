#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

matriz<int> multiplicarMatrices(const matriz<int> &A, const matriz<int> &B)
{
    int n = sz(A);
    matriz<int> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

matriz<int> sumaMatriz(const matriz<int> &A, const matriz<int> &B)
{
    int n = sz(A);
    matriz<int> sum(n, vecInt(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    return sum;
}

matriz<int> potenciaMatriz(const matriz<int> &A, int p)
{
    if (p == 1)
    {
        return A;
    }

    matriz<int> half = potenciaMatriz(A, p / 2);
    matriz<int> res = multiplicarMatrices(half, half);

    if (p % 2 != 0)
    {
        res = multiplicarMatrices(res, A);
    }

    return res;
}

matriz<int> potenciaSum(const matriz<int> &A, int n)
{
    if (n == 1)
    {
        return A;
    }

    matriz<int> half = potenciaMatriz(A, n / 2);
    matriz<int> rec = potenciaSum(A, n / 2);

    return sumaMatriz(rec, multiplicarMatrices(half, rec));
}

int main()
{
    fastio;

    int n = 10;
    matriz<int> mat = {
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