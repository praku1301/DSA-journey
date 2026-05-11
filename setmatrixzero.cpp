// brute approach hai ye
// what we had to do is ki we had to mark the rows and columns with -1 where we have 0 ofc 0 koo nhi but uske coluumns aur rows who are equal to 1 bas; and then in the end we will convert all -1 to 0
#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &arr, int i, int m)
{

    for (int j = 0; j < m; j++)
    {

        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &arr, int j, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void setMatrixZero(vector<vector<int>> &arr, int n, int m)
{

    // Step 1 // mark rows and columns with -1

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 0)
            {

                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    // Step 2:
    // convert all -1 to 0

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{

    vector<vector<int>> arr = {

        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}};

    int n = arr.size();
    int m = arr[0].size();

    setMatrixZero(arr, n, m);

    // print matrix

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

// /////////////////////////////////////BETTER
