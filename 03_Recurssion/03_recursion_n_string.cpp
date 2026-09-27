# include<iostream>
# include<string.h>
# include<vector>
using namespace std;

void reverse(string &str, int start, int end){
    if(start >= end)
        return ;
    else{
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        reverse(str,start+1,end-1);
    } 
}

void reverse_string(string &str){
    return reverse(str,0,str.size()-1);
}

// question -2 
// Check string if it is palindrom . 

bool is_palindrom(string& str, int start){
    int end=str.length()-start-1;
    // Base cases
    if(str[start]!=str[end])
        return false;
    if(start>=end)
        return true;
    is_palindrom(str, start+1);
}

bool check_palindrom(string& str){
    return is_palindrom(str ,0);
}

int power(int a , int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int result=a*power(a,b-1);
    return result;
}

int power_optimized(int a , int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int ans=power_optimized(a,b/2);
    if(b%2==0) // even
        return ans*ans;
    else
        return a*ans*ans;
}

int power_google(int x, int n){
    if(x==0)
        return 0;
    if(n==0)
        return 1;

    int output=1;
    while(n>0){
        // even power
        if(n%2==0){
            x=x*x;
            n=n/2;
        }else{
            output=output*x;
            n--;
        }
    }
    return output;
}

void swap(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

// Bubble sort
void bubble_sort(vector<int>& arr, int n){
    bool swaping=false;
    for(int i=0;i<n-1;i++){
        swaping=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaping=true;
            }
        }
        if(swaping==false)
            break;
    }
}

void sort(vector<int>& arr,int size){
    bool swaping=true;
    if(size==1)
        return ;
    else{
        for(int i=0;i<size-1;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;  
            }
        }
        sort(arr,size-1);
    }
}

void bubble_sort_recursion(vector<int>& arr){
    int size=arr.size();
    if(size==0 || size==1)
        return ;
    sort(arr,size);
}

void merge_sort(int *arr,int s,int e){
    if(s>=e)
        return ;

    int mid=(s+e)/2;
    
    // sort left part
    merge_sort(arr,s,mid);

    // sort right part 
    merge_sort(arr,mid+1,e);
    merge_array(arr,     )
}

int main(){
string str="komal lamok";
// reverse_string(str);
// cout<<str<<endl;
// cout<<check_palindrom(str)<<endl; 

cout<<"normal function : "<<power(1024,1)<<endl;
cout<<"optimized function: "<< power_optimized(1024,10)<<endl;

    return 0;
}