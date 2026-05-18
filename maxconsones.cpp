// only optimal h iska
#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // If current element is 1
        if (nums[i] == 1)
        {
            cnt++;

            maxi = max(maxi, cnt);
        }

        // If current element is 0
        else
        {
            cnt = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Maximum Consecutive Ones = "
         << findMaxConsecutiveOnes(nums);

    return 0;
}