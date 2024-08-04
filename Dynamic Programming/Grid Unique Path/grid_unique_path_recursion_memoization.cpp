#include<iostream>
#include<vector>
using namespace std;
int uniquePath(int i, int j, vector<vector<int>> &dp)
{
    // reached destination
    if (i==0 && j==0)
        return 1;

    // row or col index out of bound
    if (i<0 || j<0)
        return 0;

    if (dp[i][j]!=-1)
        return dp[i][j];

    int left=uniquePath(i, j-1, dp);    // right
    int up=uniquePath(i-1, j, dp);  // down
    
    dp[i][j]=left+up;
    return dp[i][j];
}
int main()
{
    int m, n;
    cout<<"Enter rows and cols: "<<endl;
    cin>>m>>n;
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int ans=uniquePath(m-1, n-1, dp);
    cout<<ans;
}
// time complexity: O(m*n))
// space complexity: O((m+n)+(m*n))