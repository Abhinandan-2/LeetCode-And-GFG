//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string a, int k) {
        int n = a.size(), i= 0 , j= 0,ans=-1;
        unordered_map<char,int> m;
        while(i<n){
            m[a[i]]++;
            while(j<=i&&m.size()>k){
                m[a[j]]--;
                if(m[a[j]]==0) m.erase(a[j]);
                j++;
            }
            if(m.size()==k) ans = max(i-j+1,ans);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends