// 1st type fnding element at at a position whose row and column is given by ncr method r-1Cc-1
#include <iostream>
using namespace std;

long long nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int main()
{
    int row, col;
    cin >> row >> col;

    cout << nCr(row - 1, col - 1);

    return 0;
}

// printng all the lemenets in a row
// brute
#include <iostream>
using namespace std;

long long nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

void printRow(int n)
{
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    printRow(n);

    return 0;
}

// better
#include <iostream>
using namespace std;

void printRow(int n)
{
    long long ans = 1;

    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;

        cout << ans << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    printRow(n);

    return 0;
}