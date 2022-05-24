class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        
        int n = a.size();
        vector<pair<int,int>> v(n),p(n);
        
        
        for(int i=0;i<n;i++)
        {
            v[i] = {a[i],i};
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++)
        {
            p[i].first= v[i].second;
            if(i==0)
            {
                p[i].second = 1;
            }
            else
            {
                if(v[i].first==v[i-1].first)
                    p[i].second = p[i-1].second;
                else
                    p[i].second = p[i-1].second+1;
            }
        }
        sort(p.begin(),p.end());
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i] = p[i].second;
        }
        
        return ans;
        
        
    }
};