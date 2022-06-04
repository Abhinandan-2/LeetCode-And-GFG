// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        int sum =0;
        for(int i=0;i<n;i++)
        sum += a[i];
        if(sum%2!=0)
        return 0;
        int m = sum/2;
        vector<vector<int>> dp(m+1,vector<int> (n));
        for(int i=0;i<n;i++)
        dp[0][i] = 1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    if(i==a[j])
                    dp[i][j] = 1;
                    else
                    dp[i][j]=0;
                }
                else
                {
                    if(dp[i][j-1]==1)
                    dp[i][j] = 1;
                    else
                    {
                        if(i<a[j])
                        dp[i][j] =0;
                        else
                        dp[i][j] = dp[i-a[j]][j-1];
                    }
                }
            }
        }
        
        return dp[m][n-1];
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends