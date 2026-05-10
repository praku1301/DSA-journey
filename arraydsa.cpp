//////////// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     return 0;

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // Larget element in array
//     int arr[] = {1, 5, 6, 3, 4, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int large = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > large)
//         {
//             large = arr[i];
//         }
//     }
//     cout << "Largest element is " << large;
//     return 0;
// }

//

// 2nd largest element
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
// 2nd Larget element in array
// int arr[] = {1, 5, 6, 3, 4, 1};
// int n = sizeof(arr) / sizeof(arr[0]);
// int large = arr[0];
// for (int i = 0; i < n; i++)
// {
//     if (arr[i] > large)
//     {
//         large = arr[i];
//     }
// }
// int slarge = -1;
//     int slarge = INT64_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > slarge && arr[i] != large)
//         {
//             slarge = arr[i];
//         }
//     }
//     cout << " second Largest element is " << slarge;
//     return 0;
// }

/////////////////////////// OPTIMAL 2nd largest element approach  ////////

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> getSecondOrderElements(int n, vector<int> &a)
// {

//     int largest = a[0];
//     int slargest = -1;

//     for (int i = 1; i < n; i++)
//     {

//         if (a[i] > largest)
//         {
//             slargest = largest;
//             largest = a[i];
//         }

//         else if (a[i] < largest && a[i] > slargest)
//         {
//             slargest = a[i];
//         }
//     }

//     int smallest = a[0];
//     int ssmallest = INT_MAX;

//     for (int i = 1; i < n; i++)
//     {

//         if (a[i] < smallest)
//         {
//             ssmallest = smallest;
//             smallest = a[i];
//         }

//         else if (a[i] > smallest && a[i] < ssmallest)
//         {
//             ssmallest = a[i];
//         }
//     }

//     return {slargest, ssmallest};
// }

// int main()
// {

//     vector<int> a = {5, 2, 8, 1, 9};

//     vector<int> result = getSecondOrderElements(a.size(), a);

//     cout << result[0] << " " << result[1];
// }

//////////////// CHECK IF ARRAY IS SORTED /////////////
// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if sorted
// bool isSorted(int n, vector<int> &a)
// {
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] < a[i - 1])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     int n;
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> a(n);

//     cout << "Enter elements:\n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     bool result = isSorted(n, a);

//     if (result)
//         cout << "Array is sorted";
//     else
//         cout << "Array is NOT sorted";

//     return 0;
// }

// REMOVE DUPLICATES
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    // step 1: create set
    set<int> st;

    // step 2: insert all elements into set
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    // step 3: copy unique elements back to array
    int index = 0;
    for (auto it : st)
    {
        arr[index] = it;
        index++;
    }

    // step 4: return number of unique elements
    return st.size();
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicates(arr, n);

    cout << "Unique elements:\n";

    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// FIND THE MISSING ELEMENT
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    int N = 5;
    int n = arr.size();

    for (int i = 1; i <= N; i++)
    {
        int flag = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "Missing number: " << i;
            break;
        }
    }

    return 0;
}

// BETTER APPROAACH
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    int N = 5;

    vector<int> hash(N + 1, 0);

    // mark present numbers
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    // find missing
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            cout << "Missing number: " << i;
            break;
        }
    }

    return 0;
}

// OPTIMAL APPROACH
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 5};
    int N = 5;

    long long sum = (long long)N * (N + 1) / 2;

    long long s2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        s2 += v[i];
    }

    int missing = sum - s2;

    cout << "Missing number: " << missing;

    return 0;
}
// optimal approach XOR
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 5};
    int N = 5;

    int xor1 = 0, xor2 = 0;

    // XOR of 1 to N
    for (int i = 1; i <= N; i++)
    {
        xor1 ^= i;
    }

    // XOR of array
    for (int i = 0; i < v.size(); i++)
    {
        xor2 ^= v[i];
    }

    int missing = xor1 ^ xor2;

    cout << "Missing number: " << missing;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 5};
    int N = 5;

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        xor2 ^= v[i];    // array XOR
        xor1 ^= (i + 1); // 1 to N-1 XOR
    }

    xor1 ^= N; // last number include karo

    int missing = xor1 ^ xor2;

    cout << "Missing number: " << missing;

    return 0;
} // ye ussi ka updated part hai

// MAX CONSS USED ONES
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 0;
            }
        }

        return maxi;
    }
};
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;

                if (cnt > maxi)
                {
                    maxi = cnt;
                }
            }
            else
            {
                cnt = 0;
            }
        }

        return maxi;
    }
};