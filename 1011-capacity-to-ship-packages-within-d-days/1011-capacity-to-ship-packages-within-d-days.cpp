class Solution {
    
    bool is(vector<int> &a,int m,int t)
    {
        int n= a.size() , sum =0,ans=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>m)
            {
                ans++;
                sum=a[i];
            }
        }
        ans++;
        if(ans<=t)
            return 1;
        return 0;
        
    }
    
public:
    int shipWithinDays(vector<int>& a, int t) {
        
        int h = accumulate(a.begin(),a.end(),0);
        int l = *max_element(a.begin(),a.end()) , m ,ans ,k ;
        
        while(l<=h)
        {
            m = l+(h-l)/2;
            if(is(a,m,t))
            {
                h =m-1;
                ans = m;
            }
            else
                l = m+1;
            
        }
        return ans;
        
        
    }
};