#include<iostream>
#include<vector>
using namespace std;



// Brootforce approach
int solve(int a, int b, int& ans){
    if(b==0)
        return ans;
    ans=ans*a;
    return solve(a,b-1,ans);
}   // T.c. O(b)
// S.C. O(b)

int power(int a, int b){
    int ans=1;

    if(b>=0){

        // base case
        if(a==0 && b==0)
            return 1;
        if(a==0)
            return 0;
        if(b==0)
            return 1;
        if(b==1)
            return a;

        // recursive call 
        if(b%2== 0)
            return solve(a,b,ans);
        else
            return a* solve(a,b,ans);
    }
    return ans;
}

// Divide and concore method
int solve(int a, int b){
    if(a==0 && b==0)
            return 1;
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int ans ;
    ans=solve(a,b/2);
    
    if(b%2==0)
        return ans * ans ;
    else    
        return a* ans * ans;
}



int main(){
    cout<<solve(2,10);
    return 0;
}