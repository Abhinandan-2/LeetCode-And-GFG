class Solution {
public:
    
    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& qu) {
        int n = a.size() , m =a[0].size(),count,mx;
        int x[] = {0,0,1,-1},x1;
        int y[] = {1,-1,0,0},y1;
        vector<vector<int>> vis(n,vector<int> (m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        pair<int,pair<int,int>> p ;
        mx = *max_element(qu.begin(),qu.end());
        vector<int> res(mx+1,0);
        q.push({a[0][0],{0,0}});
        vis[0][0]=1;
        for(int i=1;i<=mx;i++){
            count=0;
            while(!q.empty()&&q.top().first<i){
                p = q.top();
                q.pop();
                count++;
                for(int k=0;k<4;k++){
                    x1 = p.second.first+x[k];
                    y1 = p.second.second+y[k];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&vis[x1][y1]==0){
                        q.push({a[x1][y1],{x1,y1}});
                        vis[x1][y1]=1;
                    }
                }
            }
            res[i] = res[i-1]+count;
        }
        vector<int> ans;
        for(auto &i:qu) ans.push_back(res[i]);
        return ans;
    }
};