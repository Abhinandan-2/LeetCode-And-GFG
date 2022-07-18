class Solution {
public:
    int minSubarray(vector<int>& a, int t) {
        
        int n = a.size() ;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            sum %= t;
        }
        if(sum==0)
            return 0;
        int k = (int)sum,ans=INT_MAX,f=0;
        sum =0 ;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(sum>=t)
                f=1;
            sum %= t;
            if(sum<k&&f==1)
                sum += t;
            if(m.count(sum-k))
                ans = min(ans,i-m[sum-k]);
            m[sum%t]= i;
        }
        
        if(ans==INT_MAX||ans==n)
            return -1;
        return ans;
        
    }
};