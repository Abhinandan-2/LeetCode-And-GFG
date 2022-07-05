class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n==0)
            return  {0};
       
        vector<int> ans(n+1);
        ans[0] = 0;
        int sub = 1;
        
        for(int i=1;i<=n;i++)
        {
            if(sub*2==i)
                sub = i;
            ans[i] = ans[i-sub]+1;
        }
        
        return ans;
        
    }
};