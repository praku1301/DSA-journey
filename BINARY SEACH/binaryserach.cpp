#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << binarySearch(arr, target);

    return 0;
}