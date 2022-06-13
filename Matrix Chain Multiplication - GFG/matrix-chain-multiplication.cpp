// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int call(int a[],int s,int e,vector<vector<int>> &dp)
    {
        int n = dp.size();
        if(dp[s][e]!=-1)
        return dp[s][e];
        if(s+1==e)
        {
            dp[s][e] = 0;
            return 0;
        }
        if(s+2==e)
        {
            dp[s][e] = a[s]*a[s+1]*a[s+2];
            return dp[s][e];
        }
        
        int ans = INT_MAX,f,g,f1;
        for(int i=s+1;i<e;i++)
        {
            f = call(a,s,i,dp);
            f1 = call(a,i,e,dp);
            g = a[s]*a[i]*a[e];
            ans = min(ans,f+g+f1);
        }
        
        dp[s][e] = ans;
        return ans;
        
    }
    
    
public:
    int matrixMultiplication(int n, int a[])
    {
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        int ans = call(a,0,n-1,dp);
        
        return ans;
        
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends