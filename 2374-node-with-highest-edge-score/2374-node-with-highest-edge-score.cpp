#define ll long long
class Solution {
public:
    int edgeScore(vector<int>& a) {
        
        int n = a.size();
        vector<ll> ans(n,0);
        for(int i=0;i<n;i++)
            ans[a[i]]+=i;
        ll res =0 , in =0 ;
        for(int i=0;i<n;i++)
        {
            if(ans[i]>res)
            {
                res= ans[i];
                in = i;
            }
        }
        return in;
        
    }
};