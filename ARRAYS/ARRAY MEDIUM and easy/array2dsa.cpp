// BRUTE OF ROTATING AN ARRAY

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n;
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int k;
//     cout << "Enter rotations: ";
//     cin >> k;

//     k = k % n;

//     vector<int> temp;

//     // store first k elements
//     for (int i = 0; i < k; i++)
//         temp.push_back(arr[i]);

//     // shift remaining elements
//     for (int i = k; i < n; i++)
//         arr[i - k] = arr[i];

//     // place temp elements at end
//     for (int i = n - k; i < n; i++)
//         arr[i] = temp[i - (n - k)];

//     cout << "Rotated array: ";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

/////////////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// void leftRotate(int arr[], int n, int d)
// {
//     d = d % n;

//     reverse(arr, arr + d);
//     reverse(arr + d, arr + n);
//     reverse(arr, arr + n);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int d;
//     cin >> d;

//     leftRotate(arr, n, d);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

// MOVING ZEROES TO END BRUTE THAN OPTIMAL

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> moveZeros(int n, vector<int> a)
// {

//     // Step 1: store non-zero elements
//     vector<int> temp;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] != 0)
//         {
//             temp.push_back(a[i]);
//         }
//     }

//     // Step 2: copy non-zero elements back
//     int nz = temp.size();

//     for (int i = 0; i < nz; i++)
//     {
//         a[i] = temp[i];
//     }

//     // Step 3: fill remaining with zero
//     for (int i = nz; i < n; i++)
//     {
//         a[i] = 0;
//     }

//     return a;
// }

// int main()
// {

//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     vector<int> a(n);

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<int> result = moveZeros(n, a);

//     cout << "Array after moving zeroes: ";
//     for (int x : result)
//     {
//         cout << x << " ";
//     }

//     return 0;
// }

// OPTIMAL

// #include <bits/stdc++.h>
// using namespace std;

// void moveZeroes(vector<int> &nums)
// {

//     int n = nums.size();
//     int j = -1;

//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 0)
//         {
//             j = i;
//             break;
//         }
//     }

//     if (j == -1)
//         return;

//     for (int i = j + 1; i < n; i++)
//     {
//         if (nums[i] != 0)
//         {
//             swap(nums[i], nums[j]);
//             j++;
//         }
//     }
// }

// int main()
// {

//     int n;
//     cin >> n;

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     moveZeroes(nums);

//     for (int x : nums)
//     {
//         cout << x << " ";
//     }
// }

// UNION OF TWO SORTED ARRAYS
#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> &a, vector<int> &b)
{

    set<int> st;

    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        st.insert(b[i]);
    }

    vector<int> uni;

    for (auto it : st)
    {
        uni.push_back(it);
    }

    return uni;
}

int main()
{

    int n1;
    cin >> n1;

    vector<int> a(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    int n2;
    cin >> n2;

    vector<int> b(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    vector<int> result = unionArray(a, b);

    for (auto x : result)
    {
        cout << x << " ";
    }
}

// Intersection of array
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();

    vector<int> ans;
    vector<int> vis(n2, 0); // visited array for b

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {

            // match mila + b[j] use nahi hua pehle
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j] = 1; // mark visited
                break;      // ek match mil gaya, next i pe jao
            }

            // kyunki sorted hai (optional optimization)
            if (b[j] > a[i])
                break;
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 6, 7};

    vector<int> ans = intersection(a, b);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}