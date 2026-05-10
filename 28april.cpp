#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr)
{
    vector<int> pos, neg;

    // Step 1: separate positive & negative
    for (int x : arr)
    {
        if (x >= 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }

    // Step 2: fill alternately
    int p = 0, n = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        { // even index → positive
            arr[i] = pos[p];
            p++;
        }
        else
        { // odd index → negative
            arr[i] = neg[n];
            n++;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    vector<int> result = rearrangeArray(arr);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}

// //////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        // answer vector of size n
        vector<int> ans(n);

        // even index → positive
        int posIndex = 0;

        // odd index → negative
        int negIndex = 1;

        for (int i = 0; i < n; i++)
        {

            // if number is negative
            if (nums[i] < 0)
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            // if number is positive
            else
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};

// NEXT PERMUTATION PROBLEM FINDING NEXT POSSIBLE PERMUTATION IN O(N) TIME AND O(1) SPACE

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{

    int n = A.size();
    int ind = -1;

    // Step 1:
    // find first decreasing element from back

    for (int i = n - 2; i >= 0; i--)
    {

        if (A[i] < A[i + 1])
        {
            ind = i;
            break;
        }
    }

    // Step 2:
    // if no breakpoint found
    // means array is in descending order

    if (ind == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 3:
    // find next greater element from back

    for (int i = n - 1; i > ind; i--)
    {

        // guaranteed milega
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 4:
    // reverse remaining right half

    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{

    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    vector<int> ans = nextGreaterPermutation(A);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// //////////////////////////////////////////////////////////
// optimal code for leaders in array to dekhhna hota right me saarw chota hai usse bada koi element nahi hota, dekh ek to apni i j wali approach  usme i=0 aur fir j= i+1 se shuru fri arr[j] > arr[i] isse hum sb check krltr agar y ehogya to leader nhi h leader = false if leadrs raha to vector ans me push back easy

// optimal ye h right se max element dekho usse dekho ki kya mera wala element bda hai if yes to leader hoga nhi to ni hoga ye le code
#include <bits/stdc++.h>
using namespace std;
vector<int> leadersInArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}