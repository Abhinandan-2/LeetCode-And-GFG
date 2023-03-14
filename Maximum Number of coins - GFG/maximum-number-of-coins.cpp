//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
      int call(vector<int> &a,int l,int r,vector<vector<int>> &dp){
        if(dp[l][r]!=-1) return dp[l][r];
        int ans =0 ;
        for(int i=l+1;i<r;i++) ans = max(ans,a[l]*a[r]*a[i]+call(a,l,i,dp)+call(a,i,r,dp));
        dp[l][r] = ans;
        return ans;
    }
        int maxCoins(int n, vector <int> &a){
            a.push_back(1);
        a.insert(a.begin(),1);
         n = a.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return call(a,0,n-1,dp);
            
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends