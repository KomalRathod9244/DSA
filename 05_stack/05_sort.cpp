#include<iostream>
#include<stack>
using namespace std; 

void sort(stack<int> &s, stack<int>& temp, int target)
{
    if(temp.empty()){
        temp.push(target);
        return;
    }

    int count = 0;
    while(temp.top() < target){
        int temp_top = temp.top();
        temp.pop();
        s.push(temp_top);
        count++;
    }
    temp.push(target);

    while(count){
        int s_top = s.top();
        s.pop();
        temp.push(s_top);
    }

}
void fun(stack<int> &s, stack<int>& temp)
{
    if(s.empty()){
        for(int i=0; i < temp.size(); i++){
            s.push(temp.top());
            temp.pop();
        }
        return;
    }
    
    int top=s.top();
    s.pop();

    sort(s,temp,top);
    fun(s,temp);

}

void sortStack(stack<int> &s)
{
	if(s.empty())
        return;
    
    stack<int> temp;
    fun(s, temp);
}