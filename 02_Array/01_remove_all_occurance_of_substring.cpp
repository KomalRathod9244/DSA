#include<iostream>
#include<string.h>
using namespace std;

// Failed 
string remove_part(string str){
    string st;
    for(int i=0;str[i];i++){
        if(str[i]=='a' && i<str.length()-2){
            if(str[i+1]=='b' && str[i+2]=='c'){
                int s=i,end=i+2;
                cout<<"start: "<<s<<" end: "<<end<<endl;
                for(int j=end+1;j < str.length();j++){
                    st[s]=str[j];
                    s++;
                }
                str[s]='\0';  
                cout<<"string is : "<<str<<" string length: "<<str.length()<<endl;
                i=-1;
            }
        }
    }
    return str;
}


string remove_all_occ(string s,string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    // Or better approch , with find single call to find
    int position;
    while(position=s.find(part)!= string::npos)
        s.erase(position,part.length());
}
int main(){
    string str="daabcbaabcbc";
    cout<<remove_part(str);
    return 0;
}