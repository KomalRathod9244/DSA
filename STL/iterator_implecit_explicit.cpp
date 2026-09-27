#include<iostream>
#include<array>
using namespace std;

int main()
{
    // object a1;
    array <int,5> a1;
    array <float,3> a2={10.3f,12.4f,9.5f};
    array <float,3> a3=a2;  // size and type of both array must be same

    // [], subscript operator
    // in subscript operator there is no index bound checking, it will not through any kind of error, that's why using [] is not prefered
    for(int i=0;i<=2;i++)
        cout<<a2[i]<<" ";
    cout<<endl;

    //at() 
    for(int i=0;i<=2;i++)
        cout<<a2.at(i)<<" ";
    cout<<endl;
    //Handling Exception for Invalid index
    try{
        cout<<a2.at(3);
    }
    catch(out_of_range e){
        cout<<e.what()<<endl;
    }

    //Implicit Iterator | range-for-loop
    for(float x:a2){
        cout<<x<<" ";
    }
    cout<<endl;

    //In the above code, x gets a copy of element and not reference, so there will be no change in array elements
    for(auto x:a2){
        cout<<x<<" ";
    }
    cout<<endl;
    /* 
    //range for loop can work on normal arrays as well
    int arr[]={10,20,30,40,50};
    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;
    */

    return 0;
}