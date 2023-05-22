//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        vector<int> in(n,0);
        for(int i=1;i<n;i++){
            in[i]++;
            in[p[i]]++;
        }
        int ans =0 ;
        for(int i=0;i<n;i++) if(in[i]>1) ans++;
        return ans==0 ? ans : ans-1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends