// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    int mxIncSubSeq(vector<int> &a)
    {
        int n = a.size(),h;
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            h = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            if(h==v.size())
            v.push_back(a[i]);
            else
            v[h] = a[i];
        }
        int ans = v.size();
        
        return ans;
        
    }
    
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<m;i++)
        mp[b[i]] = i;
        
        vector<int> ans(n+1);
        ans[0] = -1;
        for(int i=0;i<n;i++)
        {
            if(mp.count(a[i]))
            ans[i+1] = mp[a[i]];
            else
            ans[i+1] = -1;
        }
        
        int res = mxIncSubSeq(ans);
        res--;
        int ans1 = n-res;
        ans1 += (m-res);
        return ans1;
        
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends