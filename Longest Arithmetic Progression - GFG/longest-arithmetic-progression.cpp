// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
        
        unordered_map<int,unordered_map<int,int>> m;
        int ans =1 , f ,h ;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                f=1;
                h = a[j]-a[i];
                unordered_map<int,int> &v = m[a[j]];
                if(v.count(h))
                f = v[h];
                f++;
                m[a[i]][h]=f;
                ans = max(ans,f);
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends