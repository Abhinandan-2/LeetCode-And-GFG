class Solution {
public:
    int swimInWater(vector<vector<int>>& a) {
        
        int n = a.size(),x1,y1;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        set<vector<int>> s;
        vector<vector<int>> v(n,vector<int> (n,-1));
        vector<int> p;
        int ans=0;
        s.insert({a[0][0],0,0});
        while(!s.empty())
        {
            p = *s.begin();
            // cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
            s.erase(s.begin());
            v[p[1]][p[2]] = 1;
            ans= max(ans,p[0]);
            if(p[1]==n-1&&p[2]==n-1)
                return ans;
            for(int i=0;i<4;i++)
            {
                x1 = p[1]+x[i];
                y1 = p[2]+y[i];
                if(x1>=0&&x1<n&&y1>=0&&y1<n&&v[x1][y1]==-1)
                    s.insert({a[x1][y1],x1,y1});
            }
        }
        return ans;
        
    }
};