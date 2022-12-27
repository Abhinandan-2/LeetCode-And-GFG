//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int n){
    
  
        int i=0, j= n-1 ;
        long long ans = 0,w,m ;
        while(i<n&&j>=0&&i<j)
        {
            w = (j-i);
            m = min(a[i],a[j]);
            ans = max(ans,w*m);
            if(a[i]<a[j])
                i++;
            else
                j--;
                
        }
        
        return ans;
        
    
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends