// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
  int call(int i,int k,int n,int t,vector<vector<int>> &dp)
  {
      if(k>t)
      return 0;
      if(i==n)
      return 1;
      
      
      if(dp[i][k]!=-1)
      return dp[i][k];
      
      int f = call(i+1,k+1,n,t,dp);
      int g = call(i+1,0,n,t,dp);
      
      long long ans = (long long)f*5;
      long long mod = 1e9+7;
      ans %= mod;
      ans += ((long long)g*21);
      ans %=mod;
      
      ans %= mod;
      dp[i][k] = ans;
      return ans;
      
  }
  
    int kvowelwords(int n, int k) {
        
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        
        int ans =call(0,0,n,k,dp);
        return ans;
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends