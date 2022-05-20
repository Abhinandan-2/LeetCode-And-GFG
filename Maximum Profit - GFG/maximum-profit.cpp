// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int call(int a[],int t,vector<vector<int>> &dp,int i)
  {
      int n = dp.size();
      
      if(i>=n)
      return 0;
      
      if(t==0)
      return 0;
      
      if(dp[i][t]!=-1)
      return dp[i][t];
      
      int h =a[i], f, ans=0,f1 ;
      for(int j=i;j<n;j++)
      {
          if(a[j]>h)
          {
              f = a[j]-h;
              f1 = call(a,t-1,dp,j+1);
              ans = max(ans,f+f1);
          }
          else
          h = a[j];
      }
      
      dp[i][t] = ans;
      return ans;
      
      
  }
  
  
    int maxProfit(int t, int n, int a[]) {
        
        vector<vector<int>> dp(n,vector<int> (t+1,-1));
        
        int ans = call(a,t,dp,0);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends