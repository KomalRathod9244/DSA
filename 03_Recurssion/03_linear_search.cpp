# include<iostream>
# include<vector>
using namespace std;


int solve(vector<int>& arr, int size,int target, int current){
    if(size==0 || current== size)
        return -1;
    if(arr[current] == target)
        return current;
    current++;
    solve(arr,size,target, current);
}

int linear_search(vector<int>&arr, int target){
    int current=0, size=arr.size();
    return solve(arr,size, target, current);
}

int main(){
    vector<int> arr={3,54,7,34,55,667,3};
    int target= 3;
    cout<<linear_search(arr,target);
}