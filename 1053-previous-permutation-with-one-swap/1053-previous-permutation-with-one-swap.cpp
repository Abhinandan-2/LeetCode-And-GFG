class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        
        int n = a.size();
        
        int mn = a[n-1] , f = -1,g=-1,mx=0;
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>mn)
            {
                f = i;
                break;
            }
            mn = a[i];
        }
        
        if(f==-1)
            return a;
        for(int i=f+1;i<n;i++)
        {
            if(a[i]<a[f])
            {
                if(a[i]>mx)
                {
                    mx = a[i];
                    g= i;
                }
            }
        }
        
        swap(a[f],a[g]);
        return a;
        
        
    }
};