//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string a, string b, int m, int n) {
        
        int c=0;
        if(n!=m) return 0;
        
        for(int i=0;i<n;i++){
            
            if(b[i]=='A') c++;
            if(a[i]=='A'){
                if(c==0) return 0;
                else c--;
            }
            else if(a[i]=='B'){
                if(c!=0) return 0;
            }
        }
        if(c!=0) return 0;
        
        for(int i=n-1;i>=0;i--){
            if(b[i]=='B') c++;
            if(a[i]=='B'){
                if(c==0) return 0;
                else c--;
            }
            else if(a[i]=='A'){
                if(c!=0) return 0;
            }
        }
        if(c!=0) return 0;
        return 1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends