class Solution {
public:
    
    
    void call(vector<int> &a,vector<int> &b,int i,int &sum,set<vector<int>> &v,int t)
    {
        int n = a.size();
        if(i>=n)
            return ;
        if(sum==t)
        {
            v.insert(b);
            return ;
        }
        for(int j=i;j<n;j++)
        {
            if(sum+a[j]<=t)
            {
                sum += a[j];
                b.push_back(a[j]);
                call(a,b,j,sum,v,t);
                sum-=a[j];
                b.pop_back();
            }
            
        }
        return ;
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t){
        
        int n = a.size();
        vector<int> b;
        set<vector<int>> v;
        int sum =0;
        call(a,b,0,sum,v,t);
        vector<vector<int>> ans;
        for(auto i:v)
        {
            ans.push_back(i);
        }
        return ans;
        
    }
};