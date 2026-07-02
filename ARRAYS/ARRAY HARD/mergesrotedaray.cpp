// brute solution with space no t acceptable soilution bu tok
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    vector<long long> arr3;

    int left = 0;
    int right = 0;

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
            arr3.push_back(arr1[left++]);
        else
            arr3.push_back(arr2[right++]);
    }

    while (left < n)
        arr3.push_back(arr1[left++]);

    while (right < m)
        arr3.push_back(arr2[right++]);

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};

    int n = 4;
    int m = 3;

    merge(arr1, arr2, n, m);

    cout << "Arr1 : ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    cout << "\nArr2 : ";
    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";
}

// optimal 1
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    int n = 4;
    int m = 5;

    merge(arr1, arr2, n, m);

    cout << "Arr1 : ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    cout << "\nArr2 : ";
    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";
}