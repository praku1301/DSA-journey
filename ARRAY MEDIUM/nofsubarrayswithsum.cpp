#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;

    mpp[0] = 1; // empty prefix sum

    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    cout << findAllSubarraysWithGivenSum(arr, k);

    return 0;
}