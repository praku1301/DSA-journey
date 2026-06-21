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
// better
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    setZeroes(matrix);

    for (auto row : matrix)
    {
        for (auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// optimal time
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // mark row
                    matrix[i][0] = 0;

                    // mark column
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        // Step 2: Set zeros except first row and first column
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: Handle first row
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};