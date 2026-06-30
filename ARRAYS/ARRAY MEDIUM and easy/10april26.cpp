// Missing no brute
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int N)
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 4, 5}; // N = 5
    cout << missingNumber(arr, 5);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int N)
{
    vector<int> hash(N + 1, 0); // size N+1, sab initially 0

    // mark present elements
    for (int i = 0; i < N - 1; i++)
    {
        hash[arr[i]] = 1;
    }

    // find missing
    for (int i = 1; i <= N; i++)
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
    vector<int> arr = {4, 1, 5, 2}; // N = 5
    cout << missingNumber(arr, 5);

    return 0;
}

///////////////////////////SUBARRAYS/////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {1, 2, 1, 1, 1}; // example
    int n = a.size();
    int k = 3;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int s = 0; // see i vector ke shuru sse shruu j bhi udhar hi rkha jaha i hai j will move th ecomplete ietratiton to i aag ebadhega than j will compelte iteration again from i to the last so we get all subarrays possible by this method now to get our solution of finding sum of the subarrays we created take s=0 than keep x from i to the place where j lasted than we just add them up get the sum than comparfe the sum to what we required comapare and initially l=0 than l= max(0, j-i+1) which ewill obv be greater j=i+1 can be used to find length of the array easily and yeah we repeat the cycle till we get the longest possible
            for (int x = i; x <= j; x++)
            {
                s += a[x];
            }
            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    cout << len;
    return 0;
}

// //////////////////// BRUTE HI OPTIMIZED ///////////////////
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 1, 1, 1}; // example
    int n = a.size();
    int k = 3;

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        int s = 0;

        for (int j = i; j < n; j++)
        {
            s += a[j];
            // we observed ki k loop ki zarurat hi nbhio jb humara  j hi whi tk jayega to x ko kyu daudana hai j ko lete chlo aur add krte chalo s me no difference nothing bas whi age badhaya jo socha tha
            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    cout << len;
    return 0;
}

/////////////////////////////////////////////////////
// BETTER+ HASHING optimal for zeroes -ves and all

#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> preSumMap;

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// OPTIMAL for postives
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();

    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;

    while (right < n)
    {

        // include current element
        sum += a[right];

        // shrink window if sum > k
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // check valid subarray
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}
