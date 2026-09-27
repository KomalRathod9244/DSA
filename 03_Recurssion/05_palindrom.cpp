#include <bits/stdc++.h>
#include<iostream> 
#include<vector>
using namespace std;

// Time Complexity  : O(log N)
// Space Complexity : O(log N)
 
void cal_binary(long long n, vector<int>&binary){
	if(n==0)
		return ;
	cal_binary(n/2,binary);
	binary.push_back(n%2);
}

bool check_pali(vector<int>&binary, int i){
	int size=binary.size();

	if(i >= size-i-1)
		return true;
	if(binary[i] != binary[size-i-1])
		return false;

	return check_pali(binary,i+1);
}

bool checkPalindrome(long long N)
{	
	vector<int>binary;
	cal_binary(N,binary);
	if(binary.size() == 1)
		return true;
	return check_pali(binary, 0);
}

int main(){

    long long n=16;
	cout<<checkPalindrome(n);

    return 0;
}