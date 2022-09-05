class Solution {
    
    bool isDis(int x,int y,vector<vector<int>> &a)
    {
        unordered_map<int,int> m;
        
        for(int i=x;i>x-3;i--)
        {
            for(int j=y;j>y-3;j--)
            {
                if(m.count(a[i][j])||a[i][j]>9||a[i][j]<1)
                    return 0;
                m[a[i][j]]++;
                    
            }
        }
        
        return 1;
    }
    
public:
    
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int ans =0 , n = a.size() , m = a[0].size(),r1,r2,r3,c1,c2,c3,d1,d2;
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<m;j++)
            {
                if(!isDis(i,j,a)) continue;
                r1 = a[i][j]+a[i][j-1]+a[i][j-2];
                if(r1!=15) continue;
                r2 = a[i-1][j]+a[i-1][j-1]+a[i-1][j-2];
                if(r2!=15) continue;
                r3 = a[i-2][j]+a[i-2][j-1]+a[i-2][j-2];
                if(r3!=15) continue;
                c1 = a[i][j]+a[i-1][j]+a[i-2][j];
                if(c1!=15) continue;
                c2 = a[i][j-1]+a[i-1][j-1]+a[i-2][j-1];
                if(c2!=15) continue;
                c3 = a[i][j-2]+a[i-1][j-2]+a[i-2][j-2];
                if(c3!=15) continue;
                d1 = a[i][j]+a[i-1][j-1]+a[i-2][j-2];
                if(d1!=15) continue;
                d2 = a[i][j-2]+a[i-1][j-1]+a[i-2][j];
                if(d2!=15) continue;
                ans++;
            }
        }
        return ans;
        
    }
};