class Solution {
public:
    long long mostPoints(vector<vector<int>>& a) {
        
        int n = a.size();
        vector<long long> ans(n);
        long long res =0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                ans[i] = a[i][0];
            else{
            if(i+a[i][1]+1<n)
                ans[i] = max(ans[i+1],(long long)a[i][0]+ans[i+a[i][1]+1]);
            else
                ans[i]= max(ans[i+1],(long long)a[i][0]);
            }
            res = max(res,ans[i]);
        }
        
        return res;
        
    }
};