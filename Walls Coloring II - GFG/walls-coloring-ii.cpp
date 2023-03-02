//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &a) {
        int n = a.size() , m = a[0].size() , firstMn = 0, in = -1 , secMn = 0, mn1,mn2,pos;
        if(n==1&&m==1) return a[0][0];
        if(m==1) return -1;
        for(int i=0;i<n;i++){
            mn1 = INT_MAX;
            mn2 = INT_MAX;
            pos = -1;
            for(int j=0;j<m;j++){
                if(j==in) a[i][j] += secMn;
                else a[i][j] += firstMn;
                if(a[i][j]<=mn1){
                    mn2 = mn1;
                    mn1 = a[i][j];
                    pos = j;
                }
                else if(a[i][j]<mn2) mn2 = a[i][j];
                
            }
            firstMn = mn1;
            secMn = mn2;
            in = pos;
        }
        return firstMn;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends