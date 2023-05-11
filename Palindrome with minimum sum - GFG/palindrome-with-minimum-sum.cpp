//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string a) {
        int n = a.size() , st = -1 , en = -1, ans =0 ;
        for(int i=0,j=n-1;i<j;i++,j--) if(a[i]!='?'||a[j]!='?'){
            st = i;
            en = j;
            break;
        }
        if(st==-1) return 0;
        for(int i=st,j=en;i<j;i++,j--){
            if(a[i]!='?'&&a[j]!='?'){
                if(a[i]!=a[j]) return -1;
                if(i!=0&&a[i-1]!='?') ans += abs(a[i]-a[i-1]);
                continue;
            }
            if(a[i]=='?'&&a[j]=='?'){
                a[i] = a[i-1];
                a[j] = a[i];
            }
            else if(a[i]!='?'){
                a[j] = a[i];
                if(i!=0&&a[i-1]!='?') ans += abs(a[i]-a[i-1]);
            }
            else{
                a[i] = a[j];
                if(i!=0&&a[i-1]!='?') ans += abs(a[i]-a[i-1]);
            }
        }
        return ans*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends