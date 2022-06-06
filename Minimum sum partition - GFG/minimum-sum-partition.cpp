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
	    int m = sum/2,ans=0;
	    vector<int> v(m+1,0), h(m+1,0);
	    v[0] = 1;
	    h[0] = 1;
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(j==0)
	                v[j] = 1;
	            else
	            {
	               if(h[j]==1)
	               v[j] = 1;
	               else
	               {
	                   if(j<a[i])
	                   v[j] = 0;
	                   else
	                   v[j] = h[j-a[i]];
	               }
	            }
	            if(v[j]==1)
	            ans = max(ans,j);
	        }
	        h = v;
	        if(ans==m)
	        break;
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