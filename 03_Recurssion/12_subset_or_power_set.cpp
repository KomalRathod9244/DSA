#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> & ans, vector<int>& output, int index)
{
    if(index>=nums.size())
    {
        ans.push_back(output);
        return ;
    }
    solve(nums, ans, output, index+1);
    output.push_back(nums[index]);
    solve(nums, ans, output, index+1);
    output.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int>output;
    int i=0  ;

    solve(nums, ans, output, i);
    return ans;
}

int main()
{
    vector<int> arr={1,2,3};
    cout<<"hello"<<endl;
    vector<vector<int>>ans = subsets(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "}" << endl;
    }
    return 0;
}