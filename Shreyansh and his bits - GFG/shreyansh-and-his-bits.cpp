//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    
    long long count(long long x) {
        
        vector<int> v;
        
        while(x){
            
            v.push_back(x%2);
            x/=2;
            
        }
        
        int n = v.size(), c=0;
        
        vector<vector<long long>> dp(n,vector<long long> (n,0));
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<=i;j++){
                
                if(j==0) dp[i][j] = i+1;
                else if(j==i) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                
                
            }
            
        }
        // for(auto i:dp){
            
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
            
        // }
        long long ans =0 ;
        
        for(int i=0;i<n;i++){
            
            if(v[i]==1){
                c++;
                if(i==0) continue;
                ans += dp[i-1][c-1];
                // cout<<i<<" "<<c<<endl;
                
            }
            
        }
        
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends