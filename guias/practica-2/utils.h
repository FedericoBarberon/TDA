#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#define fastio                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

using ll = long long;
using vecInt = std::vector<int>;
using matInt = std::vector<vecInt>;

const int INF = 1e9;
const ll LINF = 1e18;

template <typename T>
void printVec(const std::vector<T> &v)
{
    for (T x : v)
        std::cout << x << " ";
    std::cout << "\n";
}

#endif