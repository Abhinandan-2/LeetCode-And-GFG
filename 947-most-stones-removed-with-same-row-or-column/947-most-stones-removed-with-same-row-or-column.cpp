class Solution {
public:
    
    // try this one
    
    int parent[1006];
    int rank[1006];
    void make(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int node)
    {
        if(node==parent[node])
            return node; 
        return parent[node]=find(parent[node]);
    }
    void union1(int u,int v)
    {
        u=find(u);
        v=find(v);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        make(n);
        int ans=0;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    union1(i,j);
        for(int i=0;i<n;i++)
            if(parent[i]==i)
                ans++;
        return n-ans;
    }
};