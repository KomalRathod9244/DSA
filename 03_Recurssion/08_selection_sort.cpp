#include<iostream>
#include<vector>
using namespace std;

/*
void selection_sort_iterative(vector<int>& arr){
    int size=arr.size();
    if(size==0 || size == 1)
        return ;
    
    int minIndex=0;
    for(int i=0; i<size-1 ;i++){
        minIndex=i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex])
                minIndex=j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
// Time complexity = O(n) outer loop , inner loop (n-1)+(n-2)+...+1 = n(n-1)/2 = O(n²)
// Best Case = O(n²)
// Worst Case = O(n²)

// Space complexity = O(1)
*/


// Selection sort using recursion 

void solve(vector<int>& arr, int i){
    if(i==arr.size()-1)
        return ;
    int minIndex=i;
    for(int j=i+1; j<arr.size(); j++){
        if(arr[j] < arr[minIndex])
            minIndex= j;
    }
    swap(arr[i], arr[minIndex]);
    return solve(arr,i+1);
}

void selection_sort(vector<int>& arr){
    if(arr.size()==0 || arr.size()==1)
        return ;
    solve(arr,0);
}


int main(){
    vector<int> arr={3,2,1};
    selection_sort(arr);
    for(int i=0;i<arr.size() ; i++){
        cout<<arr[i]<<" ";
    }

    return 0 ;
}