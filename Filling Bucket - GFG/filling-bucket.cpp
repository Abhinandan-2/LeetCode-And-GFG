//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        if(n==1||n==2) return n;
        long long h ,mod = 1e8;
        vector<int> a(n+1);
        a[0] = 1;
        a[1] = 1;
        for(int i=2;i<=n;i++){
            h = (long long)a[i-1]+a[i-2];
            h %= mod;
            a[i] = (int)h;
        }
        return a[n];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends