class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        
        int n  = a.size(), m = 5e4+7;
        
        vector<int> first(m,-1), mx(m,-1);
        
        for(int i=n-1;i>=0;i--)
            first[a[i]] = i;
        for(int i=0;i<n;i++)
            mx[a[i]] = i;
        
        for(int i=m-2;i>=0;i--)
            mx[i] = max(mx[i],mx[i+1]);
        
        int ans =0;
        for(int i=0;i<m;i++)
        {
            if(first[i]!=-1)
            {
                ans = max(ans,mx[i]-first[i]);
            }
        }
        
        return ans;
        
        
        
        
    }
};