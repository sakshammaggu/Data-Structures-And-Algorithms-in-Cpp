// to find the number of rotations in a circularly sorted array
#include<iostream>
using namespace std;
int rotations_in_circularly_sorted_array(int a[], int size)
{
    int count=0;
    int start=0, end=size-1;
    int mid=start+((end-start)/2);
    for (int i=0; i<=mid; i++)
    {
        int x=a[i];
        a[i]=a[mid+i+1];
        a[mid+i+1]=x;
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<": "<<endl;
        cin>>a[i];
    }
    if (n%2==0)
    {
        cout<<"The array is rotated "<<rotations_in_circularly_sorted_array(a,n)<<" times"<<endl;
    }
    else
    {
        cout<<"Pls enter even size";
    }
}