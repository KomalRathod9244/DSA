#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target)
{
    if (s.empty())
    {

        s.push(target);
        return;
    }

    if (s.top() < target)
    {
        s.push(target);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, target);

    s.push(top);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int top = s.top();
    s.pop();
    sortStack(s);

    // recustion return hoga tab ye karna
    // insert in sort manner
    insertSorted(s, top);
}