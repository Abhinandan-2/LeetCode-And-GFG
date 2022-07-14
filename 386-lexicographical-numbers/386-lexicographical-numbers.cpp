class Solution {
    
    void dfs(int i,int n,vector<int> &ans)
    {
        int h;
        for(int j=0;j<=9;j++)
        {
            h = i*10;
            h += j;
            if(h<=n)
            {
                ans.push_back(h);
                dfs(h,n,ans);
            }
        }
        return ;
    }
    
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        
        for(int i=1;i<10;i++)
        {
            if(i<=n)
            {
                ans.push_back(i);
                dfs(i,n,ans);
            }
            
        }
        return ans;
    }
};