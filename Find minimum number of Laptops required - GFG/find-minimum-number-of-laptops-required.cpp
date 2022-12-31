//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int a[], int b[]) {
        vector<pair<int,int>> line;
        for(int i=0;i<n;i++) line.push_back({a[i],1});
        for(int i=0;i<n;i++) line.push_back({b[i],0});
        sort(line.begin(),line.end());
        int laptop =0 , ans =0 ;
        for(int i=0;i<2*n;i++){
            line[i].second==1 ? laptop++ : laptop--;
            ans = max(ans,laptop);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends