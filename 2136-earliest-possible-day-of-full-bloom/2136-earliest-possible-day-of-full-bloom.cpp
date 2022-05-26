class Solution {
public:
    int earliestFullBloom(vector<int>& a, vector<int>& b) {
        
        int n = a.size(),h;
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i] = {b[i],a[i]};
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>> ());
        
        int ans =0, back =0;
        for(int i=0;i<n;i++)
        {
            h = v[i].first+v[i].second+1;
            h += back;
            ans = max(ans,h);
            back += v[i].second;
        }
        return ans-1;
        
    }
};