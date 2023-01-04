//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &a) {
        int h;
        sort(a.begin(),a.end());
        vector<int> v;
        for(int i=n-2;i>=0;i--){
            v = {a[i][1],INT_MIN,INT_MIN};
            h = lower_bound(a.begin(),a.end(),v)-a.begin();
            if(h==n){
                a[i][2] = max(a[i][2],a[i+1][2]);
            }
            else{
                a[i][2] = max(a[i][2]+a[h][2],a[i+1][2]);
            }
        }
        return a[0][2];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends