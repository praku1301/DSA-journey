// brute
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    set<int> st;

    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int cnt = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == x)
                cnt++;
        }

        if (cnt > nums.size() / 3)
            st.insert(x);
    }

    vector<int> ans;

    for (auto it : st)
        ans.push_back(it);

    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3};

    vector<int> ans = majorityElement(nums);

    for (auto x : ans)
        cout << x << " ";
}

// brute hi hai bas upar se better SC
#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Skip duplicate majority elements
        if (ans.size() == 0 || ans[0] != nums[i])
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                    cnt++;
            }

            if (cnt > n / 3)
                ans.push_back(nums[i]);
        }

        // At most 2 majority elements are possible
        if (ans.size() == 2)
            break;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> ans = majorityElement(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

// hashing
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    map<int, int> mpp;

    // Frequency store
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    vector<int> ans;

    // Check frequency
    for (auto it : mpp)
    {
        if (it.second > nums.size() / 3)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 3, 2, 2, 2};

    vector<int> ans = majorityElement(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// ab aayegi approach opitmized better no topitmla par o9m20 leta tu ye dekh o(n)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int mm = (n / 3) + 1;

    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;

        if (mpp[nums[i]] == mm)
        {
            ans.push_back(nums[i]);
        }
    } // isme saath ke saath chipka diya ans laag se ek aur for loop ni chalaya

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 3, 2, 2, 2};

    vector<int> ans = majorityElement(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// optimal
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    // Find potential candidates
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
        {
            cnt1++;
        }
        else if (nums[i] == el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Verify candidates
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            cnt1++;

        if (nums[i] == el2)
            cnt2++;
    }

    vector<int> ans;
    int mini = nums.size() / 3 + 1;

    if (cnt1 >= mini)
        ans.push_back(el1);

    if (cnt2 >= mini)
        ans.push_back(el2);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 3, 2, 2, 2};

    vector<int> ans = majorityElement(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}