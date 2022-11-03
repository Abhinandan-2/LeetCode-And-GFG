//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        
        bool ans=0 ;
        int h;
        for(int i=2;i<=32;i++){
            h = log2(n)/log2(i);
            if(h+1==m){
                ans = 1;
                break;
            }
            else if(h+1<m) break;
        }
        if(ans) return "Yes";
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends