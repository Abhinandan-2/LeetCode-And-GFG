class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(),cur_max =INT_MIN,ans=0,m = max_element(a.begin(),a.end())-a.begin();
        for(int i=0;i<m;i++) a[i]>cur_max ? cur_max = a[i] : ans += cur_max-a[i];
        cur_max=INT_MIN;
        for(int i=n-1;i>m;i--) a[i]>cur_max ? cur_max = a[i] : ans += cur_max-a[i];
        return ans;
    }
};