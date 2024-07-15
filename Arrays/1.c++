//  Move all zeroes to the end.
//  Basic Approach using one more array.

//  T(C) =>>> 0(N) ->>>. because we need to traverse all elements to find the zeroes.
//  S(C) =>>> 0(N) ->>>. because of an extra array.



#include<iostream>
using namespace std;


movezeroestoend(int arr[],int n)
{
    //  Making a temp array to store all the non zero elements of array named as arr[].
    int temp[];
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0) temp.push(arr[i]);
    }

    //  Intializing a variable nz to check the length of temp containing non zero elements.
    int nz=temp.length();   
    //  Pushing all non zero elements from temp to arr.
    for(int i=0;i<nz;i++)
    {
        arr[i]=temp[i];
    }

    //  Start loop from nz variable and end it on n size of array named as arr[] push 0 in it.

    for(int i=nz;i<n;i++)
    {
        arr[i]==0;
    }

    return 0;
}



int main()
{
    int n,i;
    cout<<"Enter the no of elements you want in your array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the no of elements of you array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[n];
    }
    cout<<"The elements which is present in your arrays are right now :";
    cout<<"[ ";
    for(i=0;i<n;i++)
    {
        cout<<arr[n]<<" ";
    }
    cout<<"]";
    movezeroestoend(arr,n);
    return 0;
}