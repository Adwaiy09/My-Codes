#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// find the length of first Sub Array whose sum equals the integer X.
// We use map for fast lookup of the needed number .
// The trick is to store all sums upto individual indexes in a map , and then finding the "needed" number in the map and return its index .

int subArray(std::vector<int> &v, int &k)
{
    int length = 0;
    int runningSum = 0;
    int indexOfNeeded = 0;
    std::unordered_map<int, int> map;
    map[0] = -1;
    for (int i = 0; i < v.size(); i++)
    {
        runningSum += v[i];
        map[runningSum] = i;
        int needed = runningSum - k;
        if (map.find(needed) != map.end())
        {
            length = i - map[needed];
        }
    }

    return length;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cin >> vec[i];
    }
    int x;
    std::cin >> x;
    std::cout << "Length of Sub Array is: " << subArray(vec, x);
}
