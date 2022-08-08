class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        
        
        int n = a.size(),m;
        vector<int> v;
        v.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            m = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            if(m==v.size())
                v.push_back(a[i]);
            else
            {
                v[m] = a[i];
            }
        }
        return v.size();
        
    }
};