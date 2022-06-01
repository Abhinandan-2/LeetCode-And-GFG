class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        
        int n  = a.size();
        sort(a.begin(),a.end());
        int sum =0  , res =0 ,ans =0 ;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            res += (i+1)*(a[i]);
        }
        ans = max(ans,res);
        for(int i=1;i<n;i++)
        {
            res -= sum;
            sum -= a[i-1];
            ans = max(ans,res);
        }
        return ans;
        
        
    }
};