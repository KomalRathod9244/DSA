#include<iostream>
#include<vector>
using namespace std;

void solve_(vector<int>& arr, int x, int y , int pivot)
{
    int i=x, j=y;
    if(j>=pivot)
        return ;
    if(i<0 || i >= arr.size())
        return ;
    while(j<=pivot)
    {
        if(arr[i]<= arr[pivot]){
            i++ ;
            j++;
        }else{ 
            j++;
            if(arr[j] <= arr[pivot]){
                swap(arr[j], arr[i]);
                i++;
            }   
            if(j+1 > pivot)
                break;
        }
    }
    // left part
    solve_(arr,x,x,i-2);

    // right part
    solve_(arr,i,i, pivot);

}

void quick_sort_(vector<int>& arr){
    int n=arr.size();
    if(n==0 || n==1)
        return ;

    solve_(arr,0,0,n-1);
}



// Quick sort using a standard way, 
// 1. select a pivot element
// 2. put it at its correct place , by counting the no. smaller than pivot
// 3. then make sure all the element left to it are <= and all the element to its right are > pivot element

int partition(vector<int>& arr, int left, int right) // space =O(1), time = O(n)
{   
    int pivot=right;
    int count=0 ;
    for(int i=left ;i<right;i++)  // O(n)
    {
        if(arr[i]<=arr[pivot])
            count++;
    }
    int position= left+count;

    swap(arr[pivot],arr[position]);
    pivot= position ;
    while(left< position && right > position)   // best case O(n/2) otherwise = O(n)
    {
        while(left <= arr.size()-1 && arr[left] <= arr[pivot] ) 
            left++;
        while(arr[right] > arr[pivot] && right>=0)
            right-- ;
        if(left< position && right > position )
            if(arr[right] < arr[pivot] && arr[left]> arr[pivot])
                swap(arr[left], arr[right]);
    }
    return position ;
}

void solve(vector<int>&arr, int left, int right) // space =O(1), time = O(n * log n)
{
    // base case
    if(left>=right)
        return ;

    // partition
    int position = partition(arr, left, right);
    
    // call for left part
    solve(arr,left, position-1);

    // call for right part
    solve(arr, position+1, right);
}



void quick_sort(vector<int>& arr){
    int n=arr.size();
    if(n==0 || n==1)
        return ;
    cout<<endl<<"quick sort function "<<endl;
    solve(arr,0, n-1);
}

// Avg case and best case (when array is not sorted)
// Time - O(n log n )

// Worst case (when the given array is sorted)
// time - O(n^2)f

int main(){
    vector<int>arr={2,2,2,2,2,2,2,2,2,2,2,2,2};

    quick_sort(arr);

    cout<<endl<<"after recura: "<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}