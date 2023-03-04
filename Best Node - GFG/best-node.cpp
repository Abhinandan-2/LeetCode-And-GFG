//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    pair<long long,long long> call(vector<vector<int>> &adj,vector<int> &a,int cur,long long &ans){
        int n = adj.size();
        long long mx1 = LONG_LONG_MIN , mx2 = LONG_LONG_MIN  ,f ,s ;
        pair<long long,long long> p;
        for(auto &i:adj[cur]){
            p = call(adj,a,i,ans);
            mx1 = max(mx1,p.first);
            mx2 = max(mx2,p.second);
        }
        if(mx1==LONG_LONG_MIN) mx1 =0 ;
        if(mx2==LONG_LONG_MIN ) mx2 =0 ;
        f = mx2-a[cur];
        s = a[cur]+mx1;
        ans = max(ans,s);
        // cout<<cur<<" "<<f<<" "<<s<<endl;
        return {f,s};
    }
  
    long long bestNode(int n, vector<int> &a, vector<int> &p) {
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) adj[p[i]-1].push_back(i);
        // for(int i=0;i<n;i++){
        //     cout<<i<<"-> ";
        //     for(int j=0;j<adj[i].size();j++)
        //     cout<<adj[i][j]<<" ";
        //     cout<<endl;
        // }
        long long ans = LONG_LONG_MIN ;
        call(adj,a,0,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends