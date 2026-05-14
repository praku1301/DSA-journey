// BRUTE
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                continue;
            }

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

    vector<int> ans = twoSum(arr, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}

// BETTER
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    map<int, int> mpp;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        int num = nums[i];

        int moreNeeded = target - num;

        if (mpp.find(moreNeeded) != mpp.end())
        {

            return {mpp[moreNeeded], i};
        }

        mpp[num] = i;
    }

    return {-1, -1};
}

int main()
{

    vector<int> nums = {2, 6, 5, 8, 11};

    int target = 14;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}