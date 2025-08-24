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
void print_vec(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << "\n";
}

matInt multiplicarMatrices(const matInt &A, const matInt &B)
{
    int n = A.size();
    matInt C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Eleva matriz A a la potencia p
matInt potenciaMatriz(const matInt &A, int p)
{
    int n = A.size();
    matInt resultado(n, vector<int>(n, 0));

    // Inicializar resultado como la matriz identidad
    for (int i = 0; i < n; i++)
        resultado[i][i] = 1;

    while (p > 0)
    {
        resultado = multiplicarMatrices(resultado, A);
        p--;
    }
    return resultado;
}

matInt sumaMatriz(const matInt &A, const matInt &B)
{
    matInt sum(A.size());
    for (int i = 0; i < sum.size(); i++)
        sum[i] = vecInt(A[0].size());

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    return sum;
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

// ---------------------------------------------------
// Main
// ---------------------------------------------------
int main()
{
    fastio;

    int n = 4;
    matInt mat = {
        {2, 3, 6, 3},
        {1, 4, 7, -1},
        {5, 6, 5, 3},
        {9, 13, -4, 2}};

    auto ans = potenciaSum(mat, n);

    for (auto &row : ans)
    {
        print_vec(row);
    }
    return 0;
}