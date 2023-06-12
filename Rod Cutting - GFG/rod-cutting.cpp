//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int a[], int n) {
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = a[i];
            for(int j=i-1,k=0;k<=j;k++,j--){
                ans[i]= max(ans[i],ans[j]+ans[k]);
            }
        }
        return ans[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends