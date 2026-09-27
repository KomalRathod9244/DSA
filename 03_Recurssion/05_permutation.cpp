#include<iostream>
#include<vector>
using namespace std;

void get_ans(string user_str, int t,int tindex,string output,vector<string>& ans){
    int str_l=user_str.length();
    if(t==str_l){
        ans.push_back(output);
        return ;
    }
    
    output[tindex]=user_str[t];

    for(int i=0,j=0;i<str_l;){
        if(i==t)
            i++;
        if(j==tindex)   
            j++;
        output[j]=user_str[i];
        
        if(t==str_l)
            tindex++;
        get_ans(user_str,t+1,tindex,output,ans);
        output.pop_back();
        j++;
        i++;
        

    }
}

vector<string> permutation(string user_str)
{
    int tindex=0;
    int t=0;
    string output;
    vector<string>ans; 
    if(user_str.length()==0)
        return ans;
    
    get_ans(user_str,t,tindex,output,ans);

    return ans;
}

