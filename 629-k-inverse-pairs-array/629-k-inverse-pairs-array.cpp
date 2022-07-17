class Solution {
public:
    int kInversePairs(int n, int k) {
        
        if(n==1)
        {
            if(k==0)
                return 1;
            return 0;
        }
        if(n==2)
        {
            if(k<2)
                return 1;
            return 0;
        }
        if(n==3)
        {
            if(k==0)
                return 1;
            if(k<3)
                return 2;
            if(k==3)
                return 1;
            return 0;
        }
        int t=0;
        vector<int> v(k+1,0) , h(k+1,0);
        while(t<=k)
        {
            if(t==0)
                v[t]  =1;
            else if(t<3)
                v[t] = 2;
            else if(t==3)
                v[t] = 1;
            else
                v[t] = 0;
             t++;  
        }
        long long ans , mod  =1e9+7;
        for(int i=4;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                    h[j] = 1;
                else
                {
                    ans = (long long)h[j-1]+v[j];
                    ans %= mod;
                    h[j] = (int)ans;
                    if(j>=i)
                    {
                        h[j]-=v[j-i];
                        if(h[j]<0)
                            h[j]+=(int)mod;
                    }
                }
            }
            // for(auto p:h)
            //     cout<<p<<" ";
            // cout<<endl;
            v = h;
        }
        
        return v[k];
     
    }
};