//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &a, pair<int, int> s,
                     pair<int, int> d) {
        int n = a.size() , m = a[0].size(),ans=-1,x[] = {0,0,1,-1},y[] = {1,-1,0,0},x1,y1,h;
        queue<pair<int,int>> q;
        pair<int,int> p;
        q.push(s);
        a[s.first][s.second] = 0;
        while(!q.empty()){
            ans++;
            h = q.size();
            while(h--){
                p = q.front();
                q.pop();
                if(p==d) return ans;
                for(int k=0;k<4;k++){
                    x1 = p.first+x[k];
                    y1 = p.second+y[k];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1){
                        a[x1][y1] = 0;
                        q.push({x1,y1});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends