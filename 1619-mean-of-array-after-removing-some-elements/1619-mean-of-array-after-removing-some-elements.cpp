class Solution {
public:
    double trimMean(vector<int>& a) {
        
        int n = a.size();
        sort(a.begin(),a.end());
        int sum = accumulate(a.begin(),a.end(),0);
        int k = n/20;
        for(int i=0;i<k;i++)
            sum-=a[i];
        for(int i=n-k;i<n;i++)
            sum-=a[i];
        k*=2;
        n-=k;
        double ans = (double)sum/(double)n;
        return ans;
        
    }
};