//searching the first and last occurence of element in an sorted array ----->code_studio (prob no. 11)
#include<iostream>
using namespace std;
int first_occurence(int arr[], int n, int k)
{
    int start1=0, end1=n-1;
    int ans1=-1;
    int mid1=start1+((end1-start1)/2);
    while(start1<=end1)
    {
        if (k==arr[mid1])
        {
            ans1=mid1;
            end1=mid1-1;
        }
        else if (k>arr[mid1])
        {
            start1=mid1+1;
        }
        else if (k<arr[mid1])
        {
            end1=mid1-1;
        }
        mid1=start1+((end1-start1)/2);
    }
    return ans1;
}
int last_occurence(int arr[], int n, int k)
{
    int start2=0, end2=n-1;
    int mid2=start2+((end2-start2)/2);
    int ans2=-1;
    while(start2<=end2)
    {
        if (k==arr[mid2])
        {
            ans2=mid2;
            start2=mid2+1;
        }
        else if (k>arr[mid2])
        {
            start2=mid2-1;
        }
        else if (k<arr[mid2])
        {
            end2=mid2+1;
        }
        mid2=start2+((end2-start2)/2);
    }
    return ans2;
}
int main()
{
    int num_test_cases, n, key;
    cout<<"Enter no. of test cases: "<<endl;
    cin>>num_test_cases;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter key value: "<<endl;
    cin>>key;
    int array[n];
    for (int j=0; j<num_test_cases; j++)
    {
        for (int i=0; i<n; i++)
        {
            cout<<"Enter element "<<i+1<<" of test case "<<j+1<<": "<<endl;
            cin>>array[i];
        }
    }
    cout<<"Occurence: "<<first_occurence(array, n, key)<<" "<<last_occurence(array, n, key)<<endl;
}