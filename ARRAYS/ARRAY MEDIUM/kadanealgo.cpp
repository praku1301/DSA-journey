// brute/better approach including every possible subarray
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxsum = INT_MIN; // originally i took zero but negatibve elements bhi hai to consider that too

    for (int i = 0; i < nums.size(); i++)
    {

        int sum = 0;

        for (int j = i; j < nums.size(); j++)
        {

            sum += nums[j];
            maxsum = max(maxsum, sum);
        }
    }

    cout << "Maximum Subarray Sum = " << maxsum;

    return 0;
}

// kadane's algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxsum = INT_MIN; // originally i took zero but negatibve elements bhi hai to consider that too
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];

        if (sum > maxsum)
        {
            maxsum = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "Maximum Subarray Sum = " << maxsum;

    return 0;
}