class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        
        int n = a.size(),ans=0,c1,c2,h;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            h = a[i]+k;
            c1 = lower_bound(a.begin(),a.end(),h)-a.begin();
            c2 = upper_bound(a.begin(),a.end(),h)-a.begin();
            ans += (c2-c1);
        }
        
        return ans;
    }
};