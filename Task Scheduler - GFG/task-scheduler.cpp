//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &a) {
        unordered_map<char,int> m;
        int mx =0 , ans;
        for(auto &i:a){ m[i]++; mx = max(mx,m[i]);}
        ans = (mx-1)*(k+1);
        for(auto &i:m) if(i.second==mx) ans++;
        return max(ans,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends