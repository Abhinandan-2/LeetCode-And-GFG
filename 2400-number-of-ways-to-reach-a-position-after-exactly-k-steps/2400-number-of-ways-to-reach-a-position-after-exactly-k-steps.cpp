#define ll long long

class Solution {
    
    ll solve(map<pair<int,int>,int> &v,int s,int e,int k)
    {
       
        if(v.count({s,k}))
            return v[{s,k}];
        
        
        
        int dis = abs(e-s);
        
        
        if(dis==k)
        {
            
            
            v[{s,k}] = 1;
            
            
            return 1;
        }
        
        
     ll ans = solve(v,s+1,e,k-1),mod =1e9+7;
     
        
        ans += solve(v,s-1,e,k-1);
       
        ans %= mod;
        
        
        v[{s,k}]= (int)ans;
        
        
        return ans;
        
    }
    
public:
    int numberOfWays(int s, int e, int k) {
        
        map<pair<int,int> ,int> v;
        
        int dif = abs(e-s);
        int dif1 = k-dif;
        if(dif1%2!=0||dif>k)
            return 0;
        

        
        ll res = solve(v,s,e,k);
        
        return (int)res;
        
    }
};