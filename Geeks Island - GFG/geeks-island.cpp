//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    void call(vector<vector<int>> &a,vector<vector<int>> &v,int f){
        int n = a.size() , m= a[0].size();
        int x[] = {0,0,1,-1} , y[] = {1,-1,0,0},x1,y1;
        queue<pair<int,int>> q;
        pair<int,int> p;
        for(int i=0;i<m;i++){
            if(f==0){
                q.push({0,i});
                v[0][i] = 1;
            }
            else{
                q.push({n-1,i});
                v[n-1][i] = 1;
            }
        }
        for(int i=1;i<n;i++){
            if(f==0){
                q.push({i,0});
                v[i][0] = 1;
            }
            else{
                q.push({n-1-i,m-1});
                v[n-1-i][m-1] = 1;
            }
        }
        
        while(!q.empty()){
            p = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                x1 = p.first+x[k];
                y1 = p.second+y[k];
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&v[x1][y1]==0&&a[x1][y1]>=a[p.first][p.second]){
                    q.push({x1,y1});
                    v[x1][y1] = 1;
                }
            }
        }
        
        return ;
    }

    int water_flow(vector<vector<int>> &a,int n,int m){
        
        vector<vector<int>> v1(n,vector<int> (m,0)) , v2(n,vector<int>(m,0));
        call(a,v1,0);
        call(a,v2,1);
        int ans = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i][j]!=0&&v2[i][j]!=0) ans++;
            }
        }
        return ans;
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends