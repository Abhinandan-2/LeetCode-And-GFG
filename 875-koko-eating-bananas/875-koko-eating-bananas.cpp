class Solution {
    
    bool is(vector<int> &a,int m,int t)
    {
        int n = a.size() ;
        long long ans =0;
        for(int i=0;i<n;i++)
            ans += ((a[i]-1)/m)+1;
        if(ans<=(long long)t)
            return 1;
        return 0;
        
    }
    
public:
    int minEatingSpeed(vector<int>& a, int t) {
        
        int h = *max_element(a.begin(),a.end());
        int l = 1 , m, ans  ,k;
        
        while(l<=h)
        {
            m = l+(h-l)/2;
            if(is(a,m,t))
            {
                ans = m;
                h = m-1;
            }
            else
                l = m+1;
        }
        return ans;
        
    }
};