class Solution {
public:
    
    static bool com(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& a) {
        
        int n = a.size(),m;
        
        sort(a.begin(),a.end(),com);
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            m = lower_bound(v.begin(),v.end(),a[i][1])-v.begin();
            if(v.size()==m)
                v.push_back(a[i][1]);
            else
                v[m] = a[i][1];
        }
        
        return v.size();
    }
};