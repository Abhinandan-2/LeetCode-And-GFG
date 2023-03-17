//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &a) {
    
    long long int ans =0 ;
    int i=0, j ,f=0;
    while(i<n){
        if(a[i]==0){
            if(f==0){
                j = i;
                f=1;
            }
            ans += (i-j+1);
        }
        else{
            f = 0 ;
        }
        i++;
    }
    return ans;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends