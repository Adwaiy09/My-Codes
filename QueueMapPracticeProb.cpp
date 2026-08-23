#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    queue<int> customers;
    customers.push(101);
    customers.push(102);
    customers.push(103);
    customers.push(104);
    customers.push(105);
    customers.push(106);

    map<int, int> count;
    queue<int> order;
    while (count[customers.front()] != 2)
    {
        cout << "Front processed: " << customers.front() << endl;
        order.push(customers.front());
        if (customers.front() % 2 != 0)
        {
            count[customers.front()]++;
            customers.pop();
        }
        else
        {
            count[customers.front()]++;
            customers.push(customers.front());
            customers.pop();
        }
    }

    cout << endl;
    cout << "Times each customer was processed: " << endl;
    for (auto i : count)
    {

        cout << i.first << " processed: " << i.second << " times" << endl;
    }
    cout << endl;
    cout << "Processing order: " << endl;
    while (!order.empty())
    {
        cout << order.front() << " ";
        order.pop();
    }
    cout << endl;
    cout << "Final queue: " << endl;

    while (!customers.empty())
    {
        cout << customers.front() << " ";
        customers.pop();
    }
}