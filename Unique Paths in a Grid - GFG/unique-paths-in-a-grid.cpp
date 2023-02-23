//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &a) {
        long long mod = 1e9+7 , h ;
        for(int i=m-2;i>=0;i--) if(a[n-1][i]==1) if(a[n-1][i+1]==0) a[n-1][i] = 0;
        for(int i=n-2;i>=0;i--) if(a[i][m-1]==1) if(a[i+1][m-1]==0) a[i][m-1] = 0;
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(a[i][j]==1){
                    if(a[i][j+1]!=0&&a[i+1][j]!=0){
                        h = (long long)a[i][j+1]+a[i+1][j];
                        h %= mod;
                        a[i][j] = (int)h;
                    }
                    else if(a[i][j+1]!=0) a[i][j] = a[i][j+1];
                    else if(a[i+1][j]!=0) a[i][j] = a[i+1][j];
                    else a[i][j] = 0;
                }
            }
        }
        return a[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends