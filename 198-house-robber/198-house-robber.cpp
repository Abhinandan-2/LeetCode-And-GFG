class Solution {
public:
    int rob(vector<int>& a) {
        
        int n = a.size();
        if(n==1)
            return a[0];
        if(n==2)
            return max(a[0],a[1]);
        
        a[2] += a[0];
        for(int i=3;i<n;i++)
        {
            a[i] += max(a[i-2],a[i-3]);
        }
        
        return max(a[n-1],a[n-2]);
        
        
    }
};