#include<iostream>
#include<vector>
using namespace std;
int uniquePath(int i, int j, vector<vector<int>> &dp, int &m, int &n)
{
    dp[0][0]=1;

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i==0 && j==0)
                dp[i][j]=1;
            else
            {
                int up=0, left=0;
                if (i>0)
                    up=dp[i-1][j];
                if (j>0)
                    left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }

    return dp[m-1][n-1];
}
int main()
{
    int m, n;
    cout<<"Enter rows and cols: "<<endl;
    cin>>m>>n;
    vector<vector<int>> dp(m, vector<int> (n));
    int ans=uniquePath(m-1, n-1, dp, m, n);
    cout<<ans;
}
// time complexity: O(m*n)
// space complexity: O(m*n)