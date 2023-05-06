//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool call(int n,vector<int> &a,int k,int tar,vector<vector<int>> &dp,unordered_map<int,int> &m){
        if(dp[k][tar]!=-1) return dp[k][tar];
        if(k==1){
            dp[k][tar] = m.count(tar) ? 1 : 0;
            return dp[k][tar];
        }
        for(int i=0;i<n;i++){
            if(a[i]>=tar) break;
            if(call(n,a,k-1,tar-a[i],dp,m)){
                dp[k][tar] = 1;
                return dp[k][tar];
            }
        }
        dp[k][tar] = 0;
        return dp[k][tar];
    }
    bool makeChanges(int n, int k, int tar, vector<int> &a) {
        unordered_map<int,int> m;
        for(auto &i:a) m[i]++;
        sort(a.begin(),a.end());
        vector<vector<int>> dp(k+1,vector<int> (tar+1,-1));
        return call(n,a,k,tar,dp,m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends