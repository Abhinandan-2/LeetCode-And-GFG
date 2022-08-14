class Solution {
public:
    int superEggDrop(int k, int n) {
        
        if(k==1)
            return n;
        
        vector<int> v(n+1,0), h(n+1,0);
        
        for(int i=0;i<n;i++)
            v[i] = 0;
        
        for(int i=1;i<=k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                    h[j] = 0;
                else
                {
                    h[j] = h[j-1]+v[j-1]+1;
                    if(h[j]>n)
                        break;
                }
            }
            v= h;
        }
        
        int ans = -1;
        for(int i=0;i<=n;i++)
        {
            if(v[i]>=n)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};