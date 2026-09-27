# include<iostream>
# include<string.h>
using namespace std;

void say_number(int n){
    if(n==0)
        return ;

    say_number(n/10);
    string arr[10]={"zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cout<<arr[n%10]<<" ";
}

int main(){
    say_number(432);
    return 0;
}