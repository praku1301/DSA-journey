// BRUTE SOLUTION ofc of consecutive sequence length
#include <bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &nums, int target)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == target)
        {
            return true;
        }
    }

    return false;
}

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int longest = 1;
    for (int i = 0; i < n; i++)
    {

        int x = nums[i];
        int cnt = 1;

        while (linearSearch(nums, x + 1))
        {

            x++;
            cnt++;
        }

        longest = max(longest, cnt);
    }
    return longest;
}
int main()
{
    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int ans = longestConsecutive(nums);
    cout << "Longest Consecutive Sequence Length = " << ans;
    return 0;
}
//////////////////////////////////////////////////////////////
// BETTER IS THIS
#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &nums)
{

    if (nums.size() == 0)
    {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int n = nums.size();

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {

        // consecutive element

        if (nums[i] - 1 == lastSmaller)
        {

            cnt++;
            lastSmaller = nums[i];
        }

        // duplicate element

        else if (lastSmaller == nums[i])
        {
            continue;
        }

        // start new sequence

        else
        {

            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, cnt);
    }

    return longest;
}

int main()
{

    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout << "Longest Consecutive Sequence Length = "
         << longestSuccessiveElements(nums);

    return 0;
}

// ////////////////////////////////////////// optimAL
