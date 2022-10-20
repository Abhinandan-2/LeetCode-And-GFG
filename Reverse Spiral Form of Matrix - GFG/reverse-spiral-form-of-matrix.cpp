//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>& a)  {
        vector<int> ans;
        int t =0 , d = n-1,l =0 , r = m-1,f=0;
        while(l<=r&&t<=d){
            if(f==0){
                for(int i=l;i<=r;i++) ans.push_back(a[t][i]);
                t++;
            }
            else if(f==1){
                for(int i=t;i<=d;i++) ans.push_back(a[i][r]);
                r--;
            }
            else if(f==2){
                for(int i=r;i>=l;i--) ans.push_back(a[d][i]);
                d--;
            }
            else{
                for(int i=d;i>=t;i--) ans.push_back(a[i][l]);
                l++;
            }
            f++;
            f %= 4;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends