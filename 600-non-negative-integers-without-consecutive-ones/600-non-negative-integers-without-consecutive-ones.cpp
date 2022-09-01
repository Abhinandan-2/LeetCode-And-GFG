class Solution {
    
    void solve(int n,int &ans,unordered_map<int,int> &m,int last)
    {
        if(n==1){
            last==2 ? ans += 1 : ans+= 2;
            return ;
        }
        
        int h = log2(n)/log2(2);
        int p = pow(2,h);
        ans += m[p-1];
        
        if(p==n){
            if(p*2!=last) ans++;
            return ;
        }
        
        if(p*2!=last) solve(n-p,ans,m,p);
        return ;
    }
    
public:
    int findIntegers(int n) {
        
        int i = 7;
        unordered_map<int,int> m;
        m[1] = 2; m[3] = 3;
        
        
        while(i<=n){
            m[i] = m[i/2]+m[(i/2)/2];
            i *= 2;
            i++;
        }
        
        int ans=0;
        solve(n,ans,m,INT_MAX);
        
        return ans;
                
    }
};