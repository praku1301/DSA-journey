// for sorting 0s 1s and 2s

#include <bits/stdc++.h>
using namespace std;
void dutchflag(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 2, 0, 1, 2};
    dutchflag(nums);
    cout << "Sorted array:";
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}