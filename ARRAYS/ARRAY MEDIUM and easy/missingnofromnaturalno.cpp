// brute
#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    // Check every number from 1 to n
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;

        // Search i inside array
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }

        // If number not found
        if (flag == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    cout << "Missing Number = "
         << missingNumber(arr, n);

    return 0;
}

// better
#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    // Hash array initialized with 0
    int hash[n + 1] = {0};

    // Mark elements present in array
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }

    // Find missing number
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    cout << "Missing Number = "
         << missingNumber(arr, n);

    return 0;
}

// optimal no 1= sum method
#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    // Sum of first n natural numbers
    int sum = n * (n + 1) / 2;

    int s2 = 0;

    // Sum of array elements
    for (int i = 0; i < n - 1; i++)
    {
        s2 += arr[i];
    }

    // Missing number
    return (sum - s2);
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    cout << "Missing Number = "
         << missingNumber(arr, n);

    return 0;
}

// optimal no `2= XOR method
#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;

    // XOR of array elements
    // and numbers from 1 to n-1
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];

        xor1 = xor1 ^ (i + 1);
    }

    // XOR remaining number n
    xor1 = xor1 ^ n;

    // Missing number
    return (xor1 ^ xor2);
}

int main()
{
    int arr[] = {1, 2, 4, 5};

    int n = 5;

    cout << "Missing Number = "
         << missingNumber(arr, n);

    return 0;
}