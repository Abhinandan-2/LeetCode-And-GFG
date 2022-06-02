// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    
	    int sum =0;
	    for(int i=0;i<n;i++)
	    sum += a[i];
	    int m = sum/2+1;
	    vector<vector<int>> dp(m,vector<int> (n));
	    
	    for(int i=0;i<n;i++)
	    dp[0][i] = 1;
	    int ans =0;
	    for(int i=1;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(j==0)
	            {
	                if(i==a[j])
	                    dp[i][j] = 1;
	                else
	                    dp[i][j] = 0;
	            }
	            else
	            {
	               if(dp[i][j-1]==1)
	                   dp[i][j] =1;
	               else
	               {
	                   if(a[j]>i)
	                       dp[i][j] = 0;
	                   else
	                       dp[i][j] = dp[i-a[j]][j-1];
	               }
	            }
	        }
	        if(dp[i][n-1]==1)
	        ans = i;
	    }
	    
	    int res = sum-ans;
	    ans = abs(ans-res);
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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends