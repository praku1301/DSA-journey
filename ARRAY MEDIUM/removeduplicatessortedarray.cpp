// BRUTE
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{

    int n = arr.size();

    // create set

    set<int> st;

    // insert all elements into set

    for (int i = 0; i < n; i++)
    {

        st.insert(arr[i]);
    }

    // copy unique elements back to array

    int index = 0;

    for (auto it : st)
    {

        arr[index] = it;
        index++;
    }

    // return number of unique elements

    return index;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};

    int k = removeDuplicates(arr);

    cout << "Unique elements are: ";

    for (int i = 0; i < k; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}

// OPTIMAL
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{

    int n = arr.size();

    int i = 0;

    for (int j = 1; j < n; j++)
    {

        if (arr[i] != arr[j])
        {

            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};

    int k = removeDuplicates(arr);

    for (int i = 0; i < k; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}