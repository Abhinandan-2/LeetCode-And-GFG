class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        
        int n = a.size();
        
        if(n==1)
            return 1;
        
        int f = 0,ans =1,h;
        
        for(int i=1;i<n;i++)
        {
            h = a[i]-a[i-1];
            if(h==0)
                continue;
            if(f==0)
            {
                f = h;
                ans += 1;
            }
            else if(f>0)
            {
                if(h<0)
                {
                    ans++;
                    f = h;
                }
            }
            else
            {
                if(h>0)
                {
                    ans++;
                    f = h;
                }
            }
        }
        return ans;
    }
};