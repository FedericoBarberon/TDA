#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#define fastio                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

template <typename T>
using matriz = std::vector<std::vector<T>>;

using ll = long long;
using vecInt = std::vector<int>;
using matInt = matriz<int>;

const int INF = 1e9;
const ll LINF = 1e18;

template <typename T>
void printVec(const std::vector<T> &v)
{
    std::cout << "[";
    for (int i = 0; i < sz(v); i++)
    {
        std::cout << v[i];
        if (i < sz(v) - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";
}

template <typename T>
void printMat(const matriz<T> &m)
{
    std::cout << "[\n";
    for (int i = 0; i < sz(m); i++)
    {
        std::cout << "    ";
        printVec(m[i]);
    }
    std::cout << "]\n";
}

#endif