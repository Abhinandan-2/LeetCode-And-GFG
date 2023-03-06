//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        if(n==0) return 0;
        vector<int> v;
        while(n){
            v.push_back(n%2);
            n/=2;
        }
        reverse(v.begin(),v.end());
        int ans = 0 ;
        n = v.size();
        if(n>=1) ans += v[0];
        if(n>=2){
            ans *=2 ;
            ans += v[1];
        }
        for(int i=2;i<n;i++){
            if(v[i]==1&&v[i-1]==1&&v[i-2]==1) v[i] = 0;
            ans *= 2;
            ans += v[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends