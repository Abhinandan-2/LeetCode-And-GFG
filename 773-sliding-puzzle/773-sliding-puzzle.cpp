class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& a) {
        map<vector<vector<int>>,int> m;
        queue<vector<vector<int>>> q;
        vector<vector<int>> p,h,res ={{1,2,3},{4,5,0}};
        q.push(a);
        int ans = -1,x2,y2,x1,y1,sz;
        int x[] = {0,0,1,-1} , y[] = {1,-1,0,0};
        m[a]++;
        while(!q.empty()){
            ans++;
            sz = q.size();
            while(sz--){
                p = q.front(); q.pop();
                if(p==res) return ans;
                for(int i=0;i<2;i++)
                    for(int j=0;j<3;j++)
                        if(p[i][j]==0){x1= i;y1 =j;}
                for(int k=0;k<4;k++){
                    x2 = x1+x[k];
                    y2 = y1+y[k];
                    if(x2>=0&&x2<2&&y2>=0&&y2<3){
                        h = p;
                        h[x2][y2] = p[x1][y1];
                        h[x1][y1] = p[x2][y2];
                        if(!m.count(h)){
                            q.push(h);
                            m[h]++;
                        }
                    }
                }
            }
        }
        return -1;   
    }
};