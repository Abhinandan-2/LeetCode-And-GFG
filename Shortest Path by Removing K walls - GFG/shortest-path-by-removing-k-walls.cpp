//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        
        vector<vector<int>> wall(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> q;
        pair<int,int> p;
        wall[0][0] = mat[0][0];
        
        q.push({0,0});
        
        int x[] = {0,0,1,-1};
        int y[] = {-1,1,0,0};
        int x1,y1,sz,ans=-1;
        while(!q.empty()){
            
            sz = q.size();
            ans++;
            while(sz--){
                
                p = q.front();
                q.pop();
                
                if(p.first==n-1&&p.second==m-1) return ans;
                
                for(int u=0;u<4;u++){
                    
                    x1 = p.first+x[u];
                    y1 = p.second+y[u];
                    
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&wall[p.first][p.second]+mat[x1][y1]<=k&&wall[p.first][p.second]+mat[x1][y1]<wall[x1][y1]){
                        q.push({x1,y1});
                        wall[x1][y1] = wall[p.first][p.second]+mat[x1][y1];
                    }
                }
            }
        }
        
        return -1;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends