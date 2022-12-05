//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> a)
	{
	    int n = a.size() , m = a[0].size(),ans=0,sz,x1,y1;
	    vector<vector<int>> vis(n,vector<int> (m,-1));
	    
	    queue<pair<int,int>> q;
	    pair<int,int> p;
	    int x[] = {0,0,1,-1};
	    int y[] = {1,-1,0,0};
	    
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            
	            
	            if(a[i][j]==1){
	                
	                q.push({i,j});
	                vis[i][j] = 1;
	                a[i][j] = 0;
	                
	            }
	            
	        }
	        
	        
	    }
	    
	    while(!q.empty()){
	        
	        sz= q.size();
	        ans++;
	        while(sz--){
	            
	            p = q.front();
	            q.pop();
	            
	            for(int k=0;k<4;k++){
	                
	                x1 = p.first+x[k];
	                y1 = p.second+y[k];
	                
	                if(x1>=0&&x1<n&&y1>=0&&y1<m&&vis[x1][y1]==-1){
	                    
	                    q.push({x1,y1});
	                    vis[x1][y1] = 1;
	                    a[x1][y1] = ans;
	                    
	                }
	                
	            }
	            
	            
	        }
	        
	    }
	    
	    return a;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends