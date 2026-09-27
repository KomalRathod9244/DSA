# include<iostream>
using namespace std;

// void solve(string &str,int start,int end){
//     if(start>=end)
//         return ;
//     char temp;
//     temp=str[start];
//     str[start]=str[end];
//     str[end]=temp;

//     solve(str,start+1,end-1);
// }

// void reverse_str(string &str){
//     if(str.size()==0 || str.size() ==  1)
//         return ;
//     int start=0,end=str.size()-1;
//     solve(str,start,end);
// }

// int main(){
//     string str = "Komal Rathod";
    
//     cout<<str<<endl;
//     reverse_str(str);
    
//     cout<<str<<endl;
//     return 0 ;
// }


// reverse a string using recusion

void solve(string& str , int i){
    int size = str.size();
    if(i >= size-i-1)
        return ;
    swap(str[i], str[size - i -1]);
    solve(str, i+1);
}

void reverse_string(string& str){
    int size= str.size();
    if(size==0 || size==1)
        return ;
    solve(str,0);
}

int main(){
    string str="Komal Rathod";
    cout<<"Original string : "<<str<<endl;
    reverse_string(str);
    cout<<str<<endl;

    return 0;
}