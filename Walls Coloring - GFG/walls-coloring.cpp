//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &a, int n) {
        for(int i=1;i<n;i++){
            a[i][0] += min(a[i-1][1],a[i-1][2]);
            a[i][1] += min(a[i-1][0],a[i-1][2]);
            a[i][2] += min(a[i-1][0],a[i-1][1]);
        }
        return min({a[n-1][0],a[n-1][1],a[n-1][2]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends