//  Move all zeroes to the end.
//  Optimal appraoch using 2 pointers.

//  T(C) =>>> 0(N) ->>>. because we need to traverse all elements to find the zeroes.
//  S(C) =>>> 0(1) ->>>. because we are not consuming extra space.



#include<iostream>
using namespace std;


movezeroestoend(int arr[],int n)
{
    int j=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) j=i;
        break;
    }

    if(j==-1) return arr;
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return arr;
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