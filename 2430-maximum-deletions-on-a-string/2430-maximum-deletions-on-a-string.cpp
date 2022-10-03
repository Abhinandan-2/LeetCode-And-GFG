#define ll long long

class Solution {
    
    // ll power(ll x,ll y,ll p){
    //     ll res =1;
    //     x = x%p;
    //     if(x==0) return 0;
    // while (y > 0){
    // if (y & 1) res = (res*x) % p;
    //         y = y>>1; 
    // x = (x*x) % p;
    // }
    // return res;
    // }
    
    int call(string &a,int i,vector<int> &v,vector<vector<int>> &st){
        int n = a.size();
        if(v[i]!=-1) return v[i];
        if(st[i].size()==0){
            v[i] = 1;
            return 1;
        }
        int ans = -1,res;
        for(int j=0;j<st[i].size();j++){
            res = call(a,i+st[i][j],v,st);
            ans = max(res,ans);
        }
        v[i] = ans+1;
        return v[i];        
    }
    
public:
    int deleteString(string a) {
        int n = a.size();
        vector<int> v(n,-1);
        vector<vector<int>> st(n);
        for(int i=0;i<n;i++){
            
            int j= i , k = i+1, len=0;
            long long val1 =0 , pw = 31 ,curPow = 1, mod = 1e9+7, val2= 0;
            while(j>=0&&k<n){
                val1 += curPow*(a[j]-97);
                val1 %= mod;
                val2 *= 31;
                val2 += (a[k]-97);
                val2 %= mod;
                if(val1==val2) st[j].push_back(len+1);
                j--;
                k++;
                len++;
                curPow *= 31;
                curPow %= mod;
            } 
        }
        int ans = call(a,0,v,st);
        return ans;
    }
};