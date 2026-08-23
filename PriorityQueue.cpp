#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> cpu;
    cpu.push(12);
    cpu.push(5);
    cpu.push(8);
    cpu.push(15);
    cpu.push(3);
    cpu.push(10);
    cpu.push(7);

    int sum = 0;
    int totaltasks = 0;
    int highestpriority = cpu.top();
    queue<int> order;

    while (!cpu.empty())
    {
        cout << "Priority of task processed: " << cpu.top() << endl;
        order.push(cpu.top());
        totaltasks++;
        sum += cpu.top();
        if (cpu.top() > 8)
        {
            cpu.push(cpu.top() - 4);
            cpu.pop();
        }
        else if (cpu.top() < 6)
        {
            int x = cpu.top();
            cpu.pop();
            cpu.push(x + 5);
        }
        else
        {

            cpu.pop();
        }
    }
    cout << endl;
    cout << "Processing order: " << endl;
    while (!order.empty())
    {
        cout << order.front() << " ";
        order.pop();
    }
    cout << endl;
    cout << "Total tasks processed: " << totaltasks << endl;
    cout << "Sum: " << sum << endl;
    cout << "Highest priority ever processed: " << highestpriority << endl;
}