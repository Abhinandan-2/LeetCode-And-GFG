//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long

class Solution {
  public:
    void multiply(vector<vector<int>> &a,vector<vector<int>> &b,ll mod){
        vector<vector<int>> h(2,vector<int>(2));
        h[0][0] = (int)(((ll)a[0][0]*(ll)b[0][0]+(ll)a[0][1]*(ll)b[1][0])%mod);
        h[0][1] = (int)(((ll)a[0][0]*(ll)b[0][1]+(ll)a[0][1]*(ll)b[1][1])%mod);
        h[1][0] = (int)(((ll)a[1][0]*(ll)b[0][0]+(ll)a[1][1]*(ll)b[1][0])%mod);
        h[1][1] = (int)(((ll)a[1][0]*(ll)b[0][1]+(ll)a[1][1]*(ll)b[1][1])%mod);
        a = h;
        return;
    }
    void power(vector<vector<int>> &mat,long long int p,ll mod){
        if(p==1) return ;
        vector<vector<int>> h = mat;
        multiply(mat,mat,mod);
        power(mat,p/2,mod);
        if(p%2!=0) multiply(mat,h,mod);
        return ;
    }
    int countStrings(long long int n) {
        vector<vector<int>> mat= {{1,1},{1,0}};
        ll mod = 1e9+7;
        power(mat,n+1,mod);
        return mat[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends