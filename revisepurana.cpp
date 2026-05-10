// LARGEST ESLEMENT
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {4, 2, 7, 1, 9, 3};

    // Step 1: Sort the vector
    sort(v.begin(), v.end());

    // Step 2: Largest element = last element
    int largest = v[v.size() - 1];

    cout << "Largest element: " << largest << endl;

    return 0;
}

// ////////////// OPTIMAL ///////////
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3, 2, 1, 5, 2};

    int largest = v[0]; // Step 1: assume first is largest

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i]; // update if bigger found
        }
    }

    cout << "Largest element: " << largest << endl;

    return 0;
}

//////////// 2nd largest Brute force///
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 7, 7, 5};

    // Step 1: Sort
    sort(v.begin(), v.end());

    int n = v.size();

    // Step 2: Largest
    int largest = v[n - 1];

    int secondLargest = -1;

    // Step 3: Traverse from back
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] != largest)
        {
            secondLargest = v[i];
            break;
        }
    }

    cout << "Second Largest: " << secondLargest << endl;

    return 0;
}