#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequence(vector<int> &v)
{
    int count = 1;
    int longestSequence = 0; // minimum possible sequence is 1 , so initializing to 0 is correct.

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    if (v.size() == 1)
    {
        return 1;
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1] + 1)
        {
            count++;
            if (count > longestSequence) // using max function here is cleaner.
            {
                longestSequence = count;
            }
        }
        else if (v[i] != v[i - 1] + 1)
        {
            if (count > longestSequence)
            {
                longestSequence = count;
            }
            count = 1;
        }
    }
    return longestSequence;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
    cout << "Longest sequence: " << sequence(vec);
}