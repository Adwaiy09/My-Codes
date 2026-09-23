#include <iostream>
#include <vector>

// BOYER MOORE MAJORITY VOTE ALGORITHM to find out the element which occurs > n/2 times , given that there WILL be an element like that.
int reNum(std::vector<int> &v)
{

    int candidate;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (count == 0)
        {
            candidate = v[i];
            count++;
        }
        else if (v[i] == candidate)
        {
            count++;
        }
        else if (v[i] != candidate)
        {
            count--;
        }
    }

    return candidate;
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
    std::cout << "Element occuring most: " << reNum(vec);
}