// #include <bits/stdc++.h>
// using namespace std;

// void reverseArray(vector<int> &arr, int l, int r)
// {
//     if (l >= r)
//         return;

//     swap(arr[l], arr[r]);

//     reverseArray(arr, l + 1, r - 1);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     reverseArray(arr, 0, n - 1);

//     for (int x : arr)
//         cout << x << " ";
// }

// PALINDROME
#include <bits/stdc++.h>
using namespace std;

bool f(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;

    if (s[i] != s[s.size() - i - 1])
        return false;

    return f(i + 1, s);
}

int main()
{
    string s;
    cin >> s;

    bool ans = f(0, s);

    if (ans)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}

//