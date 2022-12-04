class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        
        long long sum= 0,l=0,r=0 , ans = INT_MAX,h,k,res;
        int f,n= a.size();
        for(int i=0;i<n;i++)
            sum+=a[i];
        
        r = sum;
        for(int i=0;i<n;i++)
        {
            l += a[i];
            r -= a[i];
            h = l/(i+1);
            if(i!=n-1)
            k = r/(n-i-1);
            else
            k =0;
            res = abs(h-k);
            if(res<ans)
            {
                ans = res;
                f = i;
            }
        }
        
        return f;
        
        
        
    }
};