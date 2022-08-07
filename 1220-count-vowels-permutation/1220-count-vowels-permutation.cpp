class Solution {
public:
    int countVowelPermutation(int n) {
        
        if(n==1)
            return 5;
        vector<int> h(5,1),v(5,1);
        long long res =0 , ans =0 ,mod = 1e9+7;
        for(int i=2;i<=n;i++)
        {
            res =0;
            for(int j=0;j<5;j++)
            {
                switch(j)
                {
                    case 0 : ans = ((long long)h[1]+h[2])+h[4];
                        break;
                    case 1 : ans = (long long)h[0]+h[2];
                        break;
                    case 2 : ans = (long long)h[1]+h[3];
                        break;
                    case 3 : ans = h[2];
                        break;
                    case 4 : ans = (long long)h[2]+h[3];
                        break;
                }
                ans %= mod;
                v[j] = (int)ans;
                res += ans;
                res %=mod;
            }
            h = v;
        }
        
        return (int)res;
        
    }
};