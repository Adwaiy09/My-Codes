#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int subArray(vector<int> &v, int &x)
{
    int finalSum = 0;
    int currSum = 0;

    for (int i = 0; i < x; i++) // initialising current sum with first subarray window.
    {
        currSum += v[i];
    }
    finalSum = currSum;                // initialising final sum with current window sum.
    for (int i = x; i < v.size(); i++) // starting loop from the next element
    {
        currSum = currSum - v[i - x] + v[i]; // here we add the element next in the vector and subtract the last one , ensuring that our no. of elements in subarray dont exceed the requirement.
        finalSum = max(currSum, finalSum);   // final sum is equal to whichever is the greater sum.
    }

    return finalSum; // final sum returned.
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }

    cout << "Max subarray sum: " << subArray(vec, k);
}