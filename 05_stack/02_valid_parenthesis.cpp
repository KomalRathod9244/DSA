#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValidParenthesis(string s)
{
    if (s.size() < 2)
        return false;

    stack<char> t_stack ;
    t_stack.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ')' ){

            if((!t_stack.empty()) && (t_stack.top() ==  '('))
                t_stack.pop();
        }

        else if (s[i] == ']' ){

            if((!t_stack.empty()) && (t_stack.top() == '[' ))
                t_stack.pop();
        }

        else if(s[i] == '}' ){

            if((!t_stack.empty()) && (t_stack.top() == '{' ))
                t_stack.pop();
        }

        else
            t_stack.push(s[i]);

    }
    if (t_stack.empty()) 
        return true;
    else
        return false;
}
