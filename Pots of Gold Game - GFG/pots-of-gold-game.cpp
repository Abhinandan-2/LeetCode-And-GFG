// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int call(vector<int> &a,int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)
        return a[i];
        if(i==j-1)
        return max(a[i],a[j]);
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int h ,k ,mn1 ,mn2,ans ;
        h = call(a,i+1,j-1,dp);
        k = call(a,i+2,j,dp);
        mn1 = min(h,k);
        k = call(a,i,j-2,dp);
        mn2 = min(h,k);
        mn1 += a[i];
        mn2 += a[j];
        ans = max(mn1,mn2);
        dp[i][j] = ans;
        return ans;
        
    }
    

    int maxCoins(vector<int>&a,int n)
    {
	    n = a.size();
	    vector<vector<int>> dp(n,vector<int> (n,-1));
	    int ans = call(a,0,n-1,dp);
	    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends