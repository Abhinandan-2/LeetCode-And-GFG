//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> a, int n) {
        
        int c = INT_MIN , r = -1 , pos = n;
        for(int i=0;i<n;i++){
            if(a[0][i]==1){
                pos= i;
                break;
            }
        }
        c = max(c,n-pos);
        r = 0;
        for(int i=1;i<n;i++){
            pos--;
            while(pos>=0&&a[i][pos]==1) pos--;
            pos++;
            if(c<n-pos){
                c = n-pos;
                r= i;
            }
        }
        return {r,c};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends