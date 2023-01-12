//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> a) {
        int ans =0, p1,p2 ;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto &i:a) q.push(i);
        n--;
        while(n--){
            p1 = q.top(); q.pop();
            p2 = q.top(); q.pop();
            ans += p1+p2;
            q.push(p1+p2);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends