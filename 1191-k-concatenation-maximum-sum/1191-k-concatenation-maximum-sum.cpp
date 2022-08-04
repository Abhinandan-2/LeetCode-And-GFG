class Solution {
    
    long long maxSubSum(vector<int> &b,int k)
    {
        vector<int> a;
        while(k--)
            a.insert(a.end(),b.begin(),b.end());
        int n = a.size() ;
        long long sum =0 ,ans =0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(sum<0)
                sum=0;
            ans = max(sum,ans);
        }
        return ans;
        
    }
    
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {
        
        int n = a.size();
        
        if(k==1)
        {
            int ans = maxSubSum(a,k);
            return ans;
        }
        
        long long second = maxSubSum(a,2);
        long long third = maxSubSum(a,3);
        
        long long ans = (k-2)*(third-second)+second , mod = 1e9+7;
        ans %= mod;
        return (int)ans;
        
    }
};