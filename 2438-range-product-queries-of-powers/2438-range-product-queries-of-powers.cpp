class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& qu) {
        int p,h,v;
        vector<int> power;
        while(1){
            p = log2(n)/log2(2);
            v = pow(2,p);
            power.push_back(v);
            if(v==n) break;
            n -= v;
        }
        reverse(power.begin(),power.end());
        vector<int> ans;
        long long res = 1,mod = 1e9+7;
        for(int i=0;i<qu.size();i++){
            res =1;
            for(int j=qu[i][0];j<=qu[i][1];j++){
                res *= power[j];
                res %= mod;
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};