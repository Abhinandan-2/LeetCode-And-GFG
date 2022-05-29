class Solution {
public:
    int maxProduct(vector<string>& a) {
        
        int n = a.size(),val,help,ans=0,h,k;
        
        vector<int> stringVal(n);
        
        for(int i=0;i<n;i++)
        {
            val = 0;
            for(int j=0;j<a[i].size();j++)
            {
                help = (1<<(a[i][j]-'a'));
                val |= help;
            }
            stringVal[i] = val;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((stringVal[i]&stringVal[j])==0)
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