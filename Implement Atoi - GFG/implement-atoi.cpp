// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string a) {
        
        int n = a.size();
        if(n==1)
        {
            if(a[0]>=48&&a[0]<=57)
            return a[0]-48;
            if(a[0]=='-')
            return 0;
            return -1;
        }
        long long ans=0;
        int f=0;
        if(a[0]=='-')
        f =1;
        else if(a[0]>=48&&a[0]<=57)
        {
            ans *= 10;
            ans += (a[0]-48);
        }
        else
        return -1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>=48&&a[i]<=57)
            {
                ans *= 10;
                ans += (a[i]-48);
            }
            else
            return -1;
        }
        if(f==1)
        ans*=-1;
        return (int)ans;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends