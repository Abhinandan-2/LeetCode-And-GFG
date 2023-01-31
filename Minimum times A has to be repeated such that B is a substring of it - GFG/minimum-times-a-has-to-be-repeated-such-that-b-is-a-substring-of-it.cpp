//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int call(string &a,string &b,int x){
        int n = a.size() , m = b.size(),i = x,j=0,ans=1;
        while(j<m){
            if(i==n) ans++;
            i %= n;
            if(a[i]!=b[j]) return -1;
            j++;
            i++;
        }
        return ans;
    }
    int minRepeats(string a, string b) {
        int ans = INT_MAX, n = a.size(),res;
        for(int i=0;i<n;i++){
            if(a[i]==b[0]){
                res = call(a,b,i);
                if(res!=-1) ans = min(ans,res);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends