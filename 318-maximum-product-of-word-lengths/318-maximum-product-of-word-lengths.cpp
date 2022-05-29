class Solution {
    
    bool is(unordered_map<char,int> &a,unordered_map<char,int> &b)
    {
        
        for(auto i:a)
        {
            if(b.count(i.first))
                return 0;
        }
        return 1; 
    }
    
public:
    int maxProduct(vector<string>& a) {
        
        int n = a.size(),ans =0,h,k;
        vector<unordered_map<char,int>> m(n);
        for(int i=0;i<n;i++)
        {
            for(auto j:a[i])
                m[i][j]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(is(m[i],m[j]))
                {
                    h = a[i].size();
                    k = a[j].size();
                    ans = max(ans,h*k);
                }
            }
        }
        return ans;
        
        
    }
};