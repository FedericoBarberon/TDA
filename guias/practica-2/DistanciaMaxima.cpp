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
struct Node
{
    T val;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;

    Node(const T &value) : val(value) {}
};

template <typename T>
int altura(const Node<T> *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    int alturaIzq = altura(tree->left);
    int alturaDer = altura(tree->right);

    return max(alturaIzq, alturaDer) + 1;
}

template <typename T>
int distanciaMaxima(const Node<T> *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    int distMaxIzq = distanciaMaxima(tree->left);
    int distMaxDer = distanciaMaxima(tree->right);

    int alturaIzq = altura(tree->left);
    int alturaDer = altura(tree->right);

    return max({alturaIzq + alturaDer, distMaxDer, distMaxIzq});
}

// ---------------------------------------------------
// Main
// ---------------------------------------------------
int main()
{
    fastio;

    // Crear nodos
    Node<int> n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9);

    // Conectar punteros
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n4.left = &n6;
    n6.left = &n7;
    n5.right = &n8;
    n8.left = &n9;

    // root del árbol
    Node<int> *root = &n1;

    auto ans = distanciaMaxima<int>(root);

    cout << ans << "\n";
    return 0;
}