class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        
        int n = a.size(),ans=0,res,h,k,in;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                res =0;
                h = a[i];
                k = a[j];
                in = lower_bound(a.begin(),a.end(),h+k)-a.begin();
                while(in<n&&a[in]==h+k)
                {
                    if(res==0)
                        res=3;
                    else
                        res++;
                    h=k;
                    k = a[in];
                    in = lower_bound(a.begin(),a.end(),h+k)-a.begin();
                }
                ans = max(ans,res);
            }
        }
        return ans;
        
    }
};