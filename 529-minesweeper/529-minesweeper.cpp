class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& a, vector<int>& b) {
        
        int n = a.size() , m = a[0].size();
        
        vector<vector<char>> ans(n,vector<char> (m));
        vector<vector<int>> v(n,vector<int> (m,0));
        int x[] = {0,0,1,1,1,-1,-1,-1};
        int y[] = {1,-1,0,1,-1,0,1,-1};
        int x1,x2,y1,y2,count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='M')
                {
                    ans[i][j] = 'M';
                    continue;
                }
                count =0;
                for(int k=0;k<8;k++)
                {
                    x1 = i+x[k];
                    y1 = j+y[k];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]=='M')
                        count++;
                }
                if(count==0)
                    ans[i][j] = 'B';
                else
                    ans[i][j] = count+48;
            }
        }
        
        queue<pair<int,int>> q;
        pair<int,int> p;
        x1 = b[0];
        y1 = b[1];
        v[x1][y1] = 1;
        if(ans[x1][y1]=='M')
            ans[x1][y1] = 'X';
        else if(ans[x1][y1]=='B'){
        q.push({x1,y1});
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            x1 = p.first;
            y1 = p.second;
            for(int k=0;k<8;k++)
            {
                x2 = x1+x[k];
                y2 = y1+y[k];
                if(x2>=0&&x2<n&&y2>=0&&y2<m&&v[x2][y2]==0)
                {
                    v[x2][y2] =1 ;
                    if(ans[x2][y2]=='B')                          
                        q.push({x2,y2});
                }
            }
        }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    a[i][j] = ans[i][j];
                }
            }
        }
        return a;
    }
};