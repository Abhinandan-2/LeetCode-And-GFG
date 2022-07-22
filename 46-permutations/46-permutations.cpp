class Solution {
public:
    
    void call(vector<int> &a,vector<int> &h,vector<int> &v,vector<vector<int>> &ans)
    {
        int m = h.size(), n = a.size();
        if(n==m)
        {
            ans.push_back(h);
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==0){
            v[i] = 1;
            h.push_back(a[i]);
            call(a,h,v,ans);
            v[i] = 0;
            h.pop_back();
            }
        }
        
        return ;
        
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        
        
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> h , v(n,0);
        
        call(a,h,v,ans);
        
        return ans;
        
        
    }
};