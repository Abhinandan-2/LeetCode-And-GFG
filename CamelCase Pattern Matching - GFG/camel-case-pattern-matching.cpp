//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> a, string b) {
        vector<string> ans;
        int k,f, m = b.size();
        for(int i=0;i<n;i++){
            k =0 ;
            f =0 ;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]>=65&&a[i][j]<=91){
                    if(b[k]!=a[i][j]) break;
                    k++;
                    if(k==m){
                        f=1;
                        break;
                    }
                }
            }
            if(f==1) ans.push_back(a[i]);
        }
        if(ans.size()==0) return {"-1"};
        sort(ans.begin(),ans.end());
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends