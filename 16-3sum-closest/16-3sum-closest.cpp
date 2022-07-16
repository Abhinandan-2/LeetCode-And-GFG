class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        
        int n = a.size(),ans= INT_MAX , ans1,h;
        sort(a.begin(),a.end());
        for(int i=n-1;i>=2;i--)
        {
            h = t-a[i];
            for(int j=0,k=i-1;j<k;)
            {
                if(a[j]+a[k]==h)
                    return t;
                
                if(ans>abs(t-(a[i]+a[j]+a[k])))
                {
                    ans = abs(t-(a[i]+a[j]+a[k]));
                    ans1 = (a[i]+a[j]+a[k]);
                }
                
                if(a[j]+a[k]>h)
                    k--;
                else
                    j++;
            }
        }
        
        return ans1;
        
    }
};