// BRUTE
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{

    int n = arr.size();

    vector<int> temp;

    // store non-zero elements

    for (int i = 0; i < n; i++)
    {

        if (arr[i] != 0)
        {

            temp.push_back(arr[i]);
        }
    }

    // number of non-zero elements

    int nz = temp.size();

    // put non-zero elements back

    for (int i = 0; i < nz; i++)
    {

        arr[i] = temp[i];
    }

    // fill remaining places with zero

    for (int i = nz; i < n; i++)
    {

        arr[i] = 0;
    }
}

int main()
{

    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    moveZeroes(arr);

    for (int x : arr)
    {

        cout << x << " ";
    }

    return 0;
}

// OPTIMAL
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{

    int n = arr.size();

    // Step 1:
    // find first zero index

    int j = -1;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {

            j = i;
            break;
        }
    }

    // if no zero exists

    if (j == -1)
    {
        return;
    }

    // Step 2:
    // start from next element after first zero

    for (int i = j + 1; i < n; i++)
    {

        // if non-zero element found

        if (arr[i] != 0)
        {

            // swap non-zero with zero

            swap(arr[i], arr[j]);

            // move j to next zero position

            j++;
        }
    }
}

int main()
{

    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    moveZeroes(arr);

    for (int x : arr)
    {

        cout << x << " ";
    }

    return 0;
}