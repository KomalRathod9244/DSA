#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void solve(string digits, vector<string>& mapping, vector<string>& ans, string output , int index){
    if(index>=digits.size()){
        ans.push_back(output);
        return ;
    }
    int digit= digits[index] - '0';
    string map_chars = mapping[digit];  

    for(int i=0;i<map_chars.size();i++){
        output+=map_chars[i];
        solve(digits, mapping, ans, output, index+1);
        output.pop_back();
    }

} 
vector<string> letterCombinations(string digits) {
    if(digits.size()==0)

        return {};
    vector<string>mapping= {"", "", "abc","def","ghi","jkl","mno","pqrs", "tuv", "wxyz"};
    vector<string>ans;
    int index=0;
    string output="";
    solve(digits, mapping , ans,output, index);
    return ans;
}

int main(){
    string digits={'2','3','4'};
    vector<string>ans = letterCombinations(digits);
    cout<<endl<<"ans is : [";
    for(int i=0 ;i<ans.size();i++){
        cout<<"\"";
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j];
        cout<<"\", ";
    }
    cout<<"]"<< endl;
    return 0;
}