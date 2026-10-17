#include<iostream>
#include<stack>
using namespace std;


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int size = myStack.size();
    stack<int> temp ;

    for(int i=1; i<=size; i++)
    {
        temp.push(myStack.top());
        myStack.pop();
    }

    myStack.push(x);

    for(int i=1; i<=size; i++)
    {
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}

void reverseStack(stack<int> &stack) 
{
    if (stack.empty())
        return ;
    int top = stack.top();
    stack.pop();

    reverseStack(stack);
    pushAtBottom(stack, top);
}