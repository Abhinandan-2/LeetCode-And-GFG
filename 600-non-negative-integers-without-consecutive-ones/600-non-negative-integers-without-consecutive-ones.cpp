class Solution {
    
    void solve(int n,int &ans,unordered_map<int,int> &m,int last)
    {
        if(n==1)
        {
            if(last==2)
                ans += 1;
            else
                ans += 2;
            return ;
        }
        
        int h = log2(n)/log2(2);
        int p = pow(2,h);
        
        if(p==n)
        {
            ans += m[p-1];
            if(p*2!=last)
            ans++;
            return ;
        }
        
        if(p*2!=last)
        {
            ans += m[p-1];
            int rem= n-p;
            solve(rem,ans,m,p);
            return ;
        }
        
        ans += m[p-1];
        
        return ;
        
    }
    
public:
    int findIntegers(int n) {
        
        unordered_map<int,int> m;
        m[1] = 2;
        m[3] = 3;
        int i = 7;
        while(i<=1e9)
        {
            m[i] = m[i/2]+m[(i/2)/2];
            i *= 2;
            i++;
        }
        int last=INT_MAX, ans=0;
        
        solve(n,ans,m,last);
        
        return ans;
                
    }
};