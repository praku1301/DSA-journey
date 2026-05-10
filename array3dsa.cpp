// BETTER SOLUTION FOR ONCE INA RRAY NOT TWICE
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 8, 8};
    map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    for (auto it : m)
    {
        if (it.second == 1)
        {
            cout << it.first;
        }
    }
    return 0;
}
// “m[key] access bhi karta hai aur agar key nahi hai to usko janam bhi de deta hai 😤”

// SUBARRAY brute
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int K = 3;
    int n = v.size();
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += v[k];
            }
            if (sum == K)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    cout << "Longest length: " << len;
    return 0;
}
