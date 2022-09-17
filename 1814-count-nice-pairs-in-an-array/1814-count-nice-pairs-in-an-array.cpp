class Solution {
    
    int reverse(int n)
    {
        int ans =0 ;
        while(n)
        {
            ans *= 10;
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    
public:
    int countNicePairs(vector<int>& a) {
        
        int n = a.size();
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            a[i] -= reverse(a[i]);
            m[a[i]]++;
        }
        
        long long ans =0 ,mod = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
            m[a[i]]--;
            ans += m[a[i]];
            ans %= mod;
        }
        return ans;
        
    }
};