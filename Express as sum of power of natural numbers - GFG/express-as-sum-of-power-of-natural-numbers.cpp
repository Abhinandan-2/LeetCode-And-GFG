// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        vector<int> a;
        int k=1;
        int res = pow(k,x);
        while(res<=n)
        {
            a.push_back(res);
            k++;
            res = pow(k,x);
        }
        // for(auto i:a)
        // cout<<i<<" ";
        vector<int> h(n+1,0) , v(n+1,0);
        long long k1,mod = 1e9+7;
        h[0] =1;
        v[0] = 1;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                {
                    v[j] = 1;
                    continue;
                }
                if(j<a[i])
                v[j] = h[j];
                else
                {
                    k1 = (long long)h[j]+h[j-a[i]];
                    k1 %= mod;
                    v[j] = (int)k1;
                }
            }
            h =v;
        }
        
        return v[n];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends