# include<iostream>
# include<vector>
using namespace std;

/*
// problem :- Check if the array is sorted using recursion 
bool is_sorted(int arr[], int size){
    
    if(arr[size-1-1] > arr[size-1])
        return false;
    if((size-1-1) <=0 )
        return true;

    is_sorted(arr,size-1);
}

int get_sum(int *arr, int size){

    if(size==1)
        return arr[0];
    if(size==0) 
        return 0;

    int sum=get_sum(arr+1,size-1)+arr[0];
    return sum;
}

bool linear_search(int * arr, int size, int target){

    if(target== arr[0])
        return true;
    if(size==0) 
        return false;
    return linear_search(arr+1,size-1,target);
}



bool binary_search_loop(int * arr, int size, int target){
    int start=0, end=size-1, mid=0;
    if(size==0) 
        return false;
    if(size==1)
        return arr[0]==target;
    while(start<=end){
        mid=(start+end)/2;
        if(target == arr[mid])
            return true;
        else if(target>arr[mid])
            start=mid+1;
        else    
            end=mid-1;
    }
    return false;
}
bool search(int *arr,int start,int end,int target){
    int ans;
    if(start>end)
        return false;
    int mid=(start+end)/2;
    if(arr[mid]==target)
        return true;
    else if(target>arr[mid])
        ans=search(arr,mid+1,end,target);
    else   
        ans=search(arr,start,mid-1,target);
    return ans;
}
// Using recursion 
bool binary_search(int *arr, int size , int target){
    return search(arr,0,size-1,target);
}

int main(){

    int arr[]={1,3,5,7,8};
    cout<<binary_search(arr,5,9);
    return 0;
} 
*/


bool solve(vector<int>&arr,int size, int prev, int next){
    if(size==0 || size==1 );
        return true;
    if(next>=size)
        return true;
    if(arr[prev] > arr[next])
        return false;

    return solve(arr,size,++prev,++next);

}
bool is_sorted(vector<int>&nums){
    int prev=0,next=1,size=nums.size();

    return solve(nums,size,prev,next);
}
 
int main(){
    vector<int >arr={3,2,3,4,5,6,7};
    cout<<is_sorted(arr)<<endl;
}