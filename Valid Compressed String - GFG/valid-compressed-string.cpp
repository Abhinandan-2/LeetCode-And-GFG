//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string a, string b) {
        int i =0 , j =0 , c =0 , n = a.size() , m = b.size();
        while(j<m){
            if(b[j]>=48&&b[j]<=57){
                c *= 10;
                c += b[j]-48;
            }
            else{
                i += c;
                c=0;
                if(i>=n||a[i]!=b[j]) return 0;
                i++;
            }
            j++;
        }
        i+=c;
        if(i!=n) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends