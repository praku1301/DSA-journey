// 2sum brute

#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
                continue;

            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}
int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    pair<int, int> ans = twoSum(arr, target);

    cout << ans.first << " " << ans.second;
    return 0;
}

// BETTER
#include <bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;

        if (mpp.find(more) != mpp.end())
        {
            return "YES";
        }

        mpp[a] = i;
    }

    return "NO";
}
////////////////////////////////////////////////////
// OPTIMAL BUT WITH INDICES
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumh(vector<int> &nums, int target)
{
    int n = nums.size();

    // Step 1: store value + index
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], i});
    }

    // Step 2: sort based on values
    sort(v.begin(), v.end());

    // Step 3: two pointer
    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = v[left].first + v[right].first;

        if (sum == target)
        {
            return {v[left].second, v[right].second};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {-1, -1};
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOVING ZEROES TO END OF ARRAY
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &arr)
{
    vector<int> temp;

    // Step 1: store non-zero elements
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    // Step 2: copy back to original array
    int nz = temp.size();
    for (int i = 0; i < nz; i++)
    {
        arr[i] = temp[i];
    }
    // Step 3: fill remaining with zeroes
    for (int i = nz; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

// /////////////////////////////////////////////////
// counting no of arrays 1s 2s and 3s consisting
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &arr)
{
    int n = arr.size();

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // Step 1: Count
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    // Step 2: Fill 0s
    for (int i = 0; i < cnt0; i++)
    {
        arr[i] = 0;
    }

    // Step 3: Fill 1s
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        arr[i] = 1;
    }

    // Step 4: Fill 2s
    for (int i = cnt0 + cnt1; i < n; i++)
    {
        arr[i] = 2;
    }
}

// DUTCH NATIONAL FLAG
#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
// ////////////////////////////////////////////////
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        // Step 1: count frequency
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        // Step 2: check majority
        for (auto it : mp)
        {
            if (it.second > n / 2)
            {
                return it.first;
            }
        }

        return -1; // if no majority (generally not needed in LC)
    }
};

// MOOVE VOTING ALGORITHM
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int el;

        // Step 1: find candidate
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        // Step 2: verify (optional in LC)
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el)
                cnt1++;
        }

        if (cnt1 > nums.size() / 2)
            return el;
        return -1;
    }
};

// MAX SUBARRAY
// KADANE'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, maxi = LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}