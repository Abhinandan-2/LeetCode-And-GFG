//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long a[], int n)
    {
    	sort(a,a+n);
    	long long ans = 1 , f ,s ;
    	ans = a[n-1];
    	f = a[n-2]*a[n-3];
    	s = a[0]*a[1];
    	if(ans>0) ans *= max(f,s);
    	else ans *= min(f,s);
    	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends