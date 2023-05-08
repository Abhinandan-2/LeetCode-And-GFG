//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string a,int m){
            int n = a.size(),val = 1,ans=0;
            vector<int> power(n);
            for(int i=0;i<n;i++) power[i] = val%=m , val *= 2;
            for(int i=n-1;i>=0;i--) if(a[i]=='1') ans += power[n-i-1], ans %= m;
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends