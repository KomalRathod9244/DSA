#include<iostream>
#include<vector>
using namespace std;



void merge_arr(vector<int>& arr, int start , int mid, int end)
{
    int left=start, right=mid+1;
    vector<int>temp;
    while(left <= mid && right <= end)
    {
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=end)
    {
        temp.push_back(arr[right]); 
        right++;
    }

    // overwrite the original array
    for(int i=0 ; i< temp.size() ; i++){
        arr[start+i]=temp[i];
    }
}

void solve(vector<int>& arr,int start , int end){
    if(start >=end)
        return ;
    
    int mid= start + (end-start)/2;
    // call for left part 
    solve(arr, start, mid);

    // call for right part 
    solve(arr, mid+1, end);

    // sort and join the tree
    merge_arr(arr, start, mid, end);
}

void merge_sort(vector<int>& arr){
    int size= arr.size();
    if(size== 0 || size==1)
        return ;
    int start=0, end=size-1;
    solve(arr,start,end); 
}

int main(){
    cout<<"hellow";
    return 0;
}