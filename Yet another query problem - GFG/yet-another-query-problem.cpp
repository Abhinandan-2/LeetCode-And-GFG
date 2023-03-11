//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int len, vector<int> &a, vector<vector<int>> &q) {
        int res =0 ; 
        vector<int> freq(n,0);
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--){
            m[a[i]]++;
            freq[i] = m[a[i]];
        }
        vector<int> ans(len,0);
        for(int i=0;i<len;i++){
            res =0 ;
            for(int j=q[i][0];j<=q[i][1];j++) if(freq[j]==q[i][2]) res++;
            ans[i] = res;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends