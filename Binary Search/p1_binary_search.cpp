//binary search algorithm
#include<iostream>
using namespace std;
int binary_search(int array[], int key, int size)
{
    int start=0, mid, end=size-1;
    // mid=(start+end)/2;
    mid=start+((end-start)/2);
    while(start<=end)
    {
        if (key==array[mid])
        {
            return mid;
        }
        else if (key>array[mid])
        {
            start=mid+1;
        }
        else if (key<array[mid])
        {
            end=mid-1;
        }
        // mid=(start+end)/2;
        mid=start+((end-start)/2);
    }

    return -1;
}
int main()
{
    int n, x, index;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter number to be found: "<<endl;
    cin>>x;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<endl;
        cin>>arr[i];
    }
    index=binary_search(arr, x, n);
    cout<<"Number "<<x<<" found at index "<<index<<endl;
}