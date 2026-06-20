#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pv;
    vector<int> nv;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            pv.push_back(nums[i]);
        }
        else
        {
            nv.push_back(nums[i]);
        }
    }

    vector<int> ans(nums.size());

    int pos = 0;

    for (auto it : pv)
    {
        ans[pos] = it;
        pos += 2;
    }

    int neg = 1;

    for (auto it : nv)
    {
        ans[neg] = it;
        neg += 2;
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = rearrangeArray(nums);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}

// better
#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n, 0);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = rearrangeArray(nums);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}

// optimal fir sign of numbers are not equal
#include <bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int> &a)
{
    vector<int> pos, neg;

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;

        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;

        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[index] = neg[i];
            index++;
        }
    }

    return a;
}

int main()
{
    vector<int> a = {1, 2, -4, -5, 3, 4};

    vector<int> ans = alternateNumbers(a);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}