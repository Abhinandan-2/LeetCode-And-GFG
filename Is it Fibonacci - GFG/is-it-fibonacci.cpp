//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> a) {
        if(n<=k){
            return a[n-1];
        }
        long long sum =0 ;
        for(auto &i:a) sum += i;
        n-=k;
        int i=0;
        while(n--){
            a.push_back(sum);
            sum+=sum;
            sum -= a[i++];
        }
        return a.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends