#include <iostream>
#include <vector>
#include <unordered_map>

int repeatNum(std::vector<int> &v)
{
    std::unordered_map<int, int> m;
    for (int i : v)
    {
        m[i]++;
        if (m[i] == 2)
        {
            return i;
        }
    }
    return -1;
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
    std::cout << "First number repeating twice: " << repeatNum(vec);
}