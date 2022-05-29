class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        
        int n = a.size(),h,pre=0;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            h = a[i];
            h += pre;
            h %= k;
            if(m.count(h))
                return 1;
            m[pre]=1;
            pre = h;
        }
        return 0;
        
        
    }
};