#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

bool conjuncionSubmatriz(const matriz<bool> &mat, int i0, int i1, int j0, int j1)
{
    bool res = true;
    for (int i = i0; i <= i1; i++)
    {
        for (int j = j0; j <= j1; j++)
        {
            res &= mat[i][j];
        }
    }
    return res;
}

vecInt cazadorDeFalsos(const matriz<bool> &mat, int i0 = 0, int i1 = -1, int j0 = 0, int j1 = -1) // Theta(log n)
{
    if (i1 == -1 && j1 == -1)
    {
        i1 = j1 = sz(mat) - 1;
    }

    if (i0 == i1 && j0 == j1)
        return {i0, j0};

    int mitadI = (i1 + i0) / 2, mitadJ = (j1 + j0) / 2;

    if (!conjuncionSubmatriz(mat, i0, mitadI, j0, mitadJ))
        return cazadorDeFalsos(mat, i0, mitadI, j0, mitadJ);

    else if (!conjuncionSubmatriz(mat, mitadI + 1, i1, j0, mitadJ))
        return cazadorDeFalsos(mat, mitadI + 1, i1, j0, mitadJ);

    else if (!conjuncionSubmatriz(mat, i0, mitadI, mitadJ + 1, j1))
        return cazadorDeFalsos(mat, i0, mitadI, mitadJ + 1, j1);

    else if (!conjuncionSubmatriz(mat, mitadI + 1, i1, mitadJ + 1, j1))
        return cazadorDeFalsos(mat, mitadI + 1, i1, mitadJ + 1, j1);

    return {};
}

int cazadorDeFalsos2(const matriz<bool> &mat, int i0 = 0, int i1 = -1, int j0 = 0, int j1 = -1) // Theta(n)
{
    if (i1 == -1 && j1 == -1)
    {
        i1 = j1 = sz(mat) - 1;
    }

    if (i0 == i1 && j0 == j1)
        return 1;

    int mitadI = (i1 + i0) / 2, mitadJ = (j1 + j0) / 2;
    int cantidad = 0;

    if (!conjuncionSubmatriz(mat, i0, mitadI, j0, mitadJ))
        cantidad += cazadorDeFalsos2(mat, i0, mitadI, j0, mitadJ);

    if (!conjuncionSubmatriz(mat, mitadI + 1, i1, j0, mitadJ))
        cantidad += cazadorDeFalsos2(mat, mitadI + 1, i1, j0, mitadJ);

    if (!conjuncionSubmatriz(mat, i0, mitadI, mitadJ + 1, j1))
        cantidad += cazadorDeFalsos2(mat, i0, mitadI, mitadJ + 1, j1);

    if (!conjuncionSubmatriz(mat, mitadI + 1, i1, mitadJ + 1, j1))
        cantidad += cazadorDeFalsos2(mat, mitadI + 1, i1, mitadJ + 1, j1);

    return cantidad;
}

int main()
{
    fastio;

    matriz<bool> mat = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 0, 1},
    };

    // auto ans = cazadorDeFalsos(mat);
    auto ans = cazadorDeFalsos2(mat);

    printMat(mat);
    // printVec(ans);
    cout << ans << "\n";
    return 0;
}
