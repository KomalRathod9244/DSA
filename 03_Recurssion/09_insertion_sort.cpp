# include<iostream>
#include<vector>
using namespace std;
// Time complexity = O(n * n(n-1)/2) = O(n^2) - Worst case
// for best case O(n) - since array already sorted h, to left traverse karna hi nhi , bs 1-1 element se age bado and usee ek prev element se compare karo

// Space complexity = O(n) - for recusive approach
// O(1) - for iterative method

void solve(vector<int>& arr, int i){
    int size =arr.size();
    if(i >= size)
        return ;
    
    for(int j= i; j>=1; j--){
        if(arr[j] < arr[j-1])
            swap(arr[j], arr[j-1]);
        else    
            break;
    }
    
        return solve(arr,i+1);

}

void insertion_sort(vector<int>& arr){
    int size=arr.size();
    if(size==0 || size==1)
        return ;
    solve(arr, 1);
}

int main(){
    vector<int> arr={3,2,1};
    insertion_sort(arr);
    for(int i=0;i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}