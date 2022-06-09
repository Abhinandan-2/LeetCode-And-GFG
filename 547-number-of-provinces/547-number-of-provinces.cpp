class Solution {
    
    int find_set(int a,vector<int> &p)
    {
        if(a==p[a])
            return a;
        return p[a] = find_set(p[a],p);
    }
    
    void union_set(int x,int y,vector<int> &p,vector<int> &s)
    {
        x = find_set(x,p);
        y = find_set(y,p);
        if(x!=y)
        {
            if(x>y)
                swap(x,y);
            p[x] = y;
            s[y] += s[x];
        }
        
        return ;
    }
    
public:
    int findCircleNum(vector<vector<int>>& a) {
        
        int n= a.size(),x,y;
        vector<int> p(n) , s(n,1);
        
        for(int i=0;i<n;i++)
            p[i] = i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    x = find_set(i,p);
                    y = find_set(j,p);
                    if(x!=y)
                        union_set(i,j,p,s);
                }
            }
        }
        
        int ans =0 ;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            x = find_set(i,p);
            if(!m.count(x))
            {
                m[x]++;
                ans++;
            }
        }
        
        return ans;
        
        
        
    }
};