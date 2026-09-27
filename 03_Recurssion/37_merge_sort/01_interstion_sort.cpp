#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &arr){
    int i,j,target;
    for(int i=1;i<arr.size();i++){
        target=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>target){
            arr[j+1]=arr[j];
            j--;   
        }
        arr[j+1]=target;
    }
}

void insertion_sort_func(vector<int>& arr, int target_index){
    int size=arr.size();
    if(target_index>size-1)
        return ;
    int i,target=arr[target_index];
    for(i=target_index-1;i>=0;i--){
        if(arr[i]<=target)
            break;
        arr[i+1]=arr[i];
    }
    arr[i+1]=target;
    target_index++;
    insertion_sort_func(arr,target_index);
}

void insertion_sort_recursion(vector<int >& arr){
    int size=arr.size();
    if(size==0 || size==1)
        return ;
    insertion_sort_func(arr,1);
}

void selection_sort(vector<int>&arr){
    int size=arr.size();
    int min=arr[0];
    for(int i=1;i<size;i++){}
}

int main(){

    return 0;
}
