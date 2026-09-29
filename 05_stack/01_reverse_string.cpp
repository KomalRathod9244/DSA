#include<iostream>
#include<stack>
using namespace std;




int main(){
    string name = "komal rathod";

    // taking user input
    int size =0 ;

    cout<<"enter the size of the string : "<<endl;
    cin>>size;

    stack<char> s ;

    for(int i =0; i<size; i++){
        s.push(name[i]);
    }
    for(int i=0 ; i<size; i++){
        name[i]= s.top();
        
        s.pop();
    }


    return 0;
}