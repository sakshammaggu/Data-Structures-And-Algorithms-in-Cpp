#include<iostream>
using namespace std;
int uniquePath(int i, int j)
{
    // reached destination
    if (i==0 && j==0)
        return 1;

    // row or col index out of bound
    if (i<0 || j<0)
        return 0;

    int left=uniquePath(i, j-1);    // right
    int up=uniquePath(i-1, j);  // down
    
    int ans=left+up;
    return ans;
}
int main()
{
    int m, n;
    cout<<"Enter rows and cols: "<<endl;
    cin>>m>>n;
    int ans=uniquePath(m-1, n-1);
    cout<<ans;
}
// time complexity: O(2^(m*n))
// space complexity: O(m+n)