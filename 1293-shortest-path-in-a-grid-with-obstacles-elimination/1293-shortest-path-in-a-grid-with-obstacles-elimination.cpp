class Solution {
public:
    vector<int>dx{0,0,1,-1};
    vector<int> dy{1,-1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {    
        int n = grid.size();
        int m = grid[0].size();
        bool visited[n+1][m+1][k+10];
        memset(visited,false,sizeof(visited));
        queue<tuple<int,int,int,int>> q; // x y kUsed dist
        tuple src = make_tuple(0,0,0,0);
        q.push(src);
        visited[0][0][0]=true;
        while(!q.empty()){
            tuple f = q.front();
            q.pop();
            int x = get<0>(f);
            int y = get<1>(f);
            int kUsed=get<2>(f);
            int dist = get<3>(f);
            if(x==n-1 and y==m-1) return dist;
            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 and newX<n and newY>=0 and newY<m){
                   int tempk = kUsed;
                    if(grid[newX][newY]==1) tempk++;
                    if(!visited[newX][newY][tempk] and tempk<=k){
                        visited[newX][newY][tempk] = true;
                        q.push(make_tuple(newX,newY,tempk,dist+1));
                    }
                }
            }
            
        }
        return -1;
    }
};