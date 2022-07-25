class Solution {
    
    int index(vector<int> &a,int t,int f)
    {
        int n = a.size();
        
        int l=0 , h = n-1 , m , ans=-1;
        
        while(l<=h)
        {
            m = l+(h-l)/2;
            
            if(a[m]==t)
            {
                ans = m;
                if(f==0)
                    h =m-1;
                else
                    l = m+1;
            }
            else if(a[m]<t)
                l = m+1;
            else
                h = m-1;
        }
        
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& a, int t) {
        
        int n = a.size();
        
        int lower , higher ;
        
        lower = index(a,t,0);
        if(lower==-1)
            return {-1,-1};
        higher = index(a,t,1);
        
        return {lower,higher};
        
    }
};