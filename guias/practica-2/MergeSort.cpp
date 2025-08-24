#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const long long LINF = 1e18;

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

vector<int> merge(const vector<int> &l, const vector<int> &r)
{
    vector<int> merged(l.size() + r.size());
    int i = 0, j = 0, k = 0;

    while (i < l.size() && j < r.size())
    {
        if (l[i] < r[j])
        {
            merged[k++] = l[i++];
        }
        else
        {
            merged[k++] = r[j++];
        }
    }

    while (i < l.size())
    {
        merged[k++] = l[i++];
    }
    while (j < r.size())
    {
        merged[k++] = r[j++];
    }

    return merged;
}

vector<int> mergeSort(const vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }

    vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> right(arr.begin() + arr.size() / 2, arr.end());

    vector<int> sortedLeft = mergeSort(left);
    vector<int> sortedRight = mergeSort(right);

    return merge(sortedLeft, sortedRight);
}

// ---------------------------------------------------
// Main
// ---------------------------------------------------
int main()
{
    fastio;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = mergeSort(arr);

    print_vec(ans);
    return 0;
}
