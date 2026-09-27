# include<iostream>
#include<string>
#include<vector>
using namespace std;

void get_ans(string digit,int index, string output,vector<string>& ans,string mapping[]){
    
    // base case 
    if(index>=digit.length()){
        ans.push_back(output);
        return ;
    }
    int number=digit[index] - '0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        get_ans(digit,index+1,output,ans,mapping);
        output.pop_back();
    }
    
}

vector<string> print_pattern(string digit){
    vector<string>ans;
    string output="";
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


    if(digit.length()==0) 
        return ans;
    get_ans(digit,index,output,ans,mapping);
    return ans;
}


int main(){
    vector<string>ans=print_pattern("23");
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<", ";
    return 0;  
}



