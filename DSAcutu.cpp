// #include <bits/stdc++.h>

// namespace std;

// int main(){

//     return 0;
////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
void printpair()
{
    // pair<int, int> p = {1, 3};
    // cout << p.first << " " << p.second << " ";

    // pair<int, pair<int, int>> x = {1, {3, 4}};
    // cout << x.second.second << '\n';

    pair<int, int> arr[] = {{1, 3}, {2, 5}, {4, 8}};
    cout << arr[1].second;
}
void explainvector()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    // vector<pair<int, int>> vec;
    // vec.push_back({1, 3});
    // vec.emplace_back(2, 5);

    // cout << vec[0].first << " " << vec[0].second << endl;

    // vector<int> x(5, 100);
    // vector<int> y(5);
    // cout << x[1];
    // cout << y[3];

    vector<int> v1(5, 20);
    // vector<int> v2(v1);
    // cout << v2[3] << endl;

    vector<int>::iterator it = v1.begin();
    it++;
    cout << *(it) << " ";

    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
}
void explainlist()
{
    list<int> ls;
    ls.push_front(5);
}

void basicsmaths()
{

    int N;
    cin >> N; // input number

    while (N > 0)
    {
        int digit = N % 10;   // extract last digit
        cout << digit << " "; // print digit

        N = N / 10; // remove last digit (integer division)
    }
}
void revofno()
{

    int reverse(int x)
    {
        int revnum = 0;

        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;

            // OVERFLOW CHECK (before multiplying)
            if (revnum > INT_MAX / 10 ||
                (revnum == INT_MAX / 10 && digit > 7))
                return 0;

            if (revnum < INT_MIN / 10 ||
                (revnum == INT_MIN / 10 && digit < -8))
                return 0;

            revnum = revnum * 10 + digit;
        }

        return revnum;
    }
}
void recursion()
{
}
int main()
{
    // printpair();
    // explainvector();
    // explainlist();

    // int a[] = {1, 5, 6, 8, 9, 20};
    // int n = sizeof(a) / sizeof(a[0]);
    // int ind = lower_bound(a, a + n, 5) - a;
    // cout << ind + 1 << endl;

    // int A[] = {2, 5, 6, 7, 8, 8};
    // int y = sizeof(A) / sizeof(A[0]);
    // int abs = lower_bound(A, A + y, 7) - A;
    // if (abs != y && A[abs] == 7)
    // {
    //     cout << abs << '\n';
    // }
    // else
    // {
    //     cout << -1;
    // }

    // string s = "123";
    // do
    // {
    //     cout << s << endl;
    // } while (next_permutation(s.begin(), s.end()));

    basicsmaths();
    revofno();
    return 0;
}
