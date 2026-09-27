#include<iostream>
#include<vector>
using namespace std;

/*
Time complexity:-
Best Case  : O(n)
Worst Case : O(n²)

Space complexity: 
Lekin dhyan do:

solve()
    -> bubble() complete hota hai
    -> bubble() return karta hai
    -> tab next solve() call hota hai

Yaani: bubble recursion stack aur next solve recursion stack, ek saath grow nahi kar rahe.

Maximum active stack roughly: O(n) hi rahega.

So: Space Complexity = O(n)
*/


bool bubble(vector<int>& arr, int start, int end, bool flag){
    if(start==end)
        return flag;

    if(arr[start] > arr[start+1]){
        swap(arr[start],arr[start+1]);
        flag=true;
    }

    bubble(arr,start+1 ,end, flag);
}
void solve(vector<int>& arr, int end){
    if(end==0)
        return ;
    bool flag=false;
    flag=bubble(arr, 0, end, flag);
    if (!flag)
        return ;
    end=end-1;
    solve(arr,end);
}

void bubble_sort(vector<int>& arr){
    if(arr.size()==0 || arr.size()==1)
        return ;

    int end=arr.size()-1;
    solve(arr,end);
}

int main(){
    vector<int> arr = {2,3,22,45,35,23,2};
    bubble_sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return  0;
}