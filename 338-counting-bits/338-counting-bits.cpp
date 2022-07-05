class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n==0)
            return  {0};
        if(n==1)
            return {0,1};
        if(n==2)
            return {0,1,1};
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        int sub = 2;
        
        for(int i=3;i<=n;i++)
        {
            if(sub*2==i)
                sub = i;
            // co/ut<<i<<" "<<sub<<" ";
            ans[i] = ans[i-sub]+1;
            // cout<<sub<<" ";
        }
        
        return ans;
        
    }
};