class Solution {
    
    string change(int n,int b)
    {
        string ans;
        while(n)
        {
            ans.push_back(n%b+48);
            n/=b;
        }
        return ans;
    }
    
    bool ispali(string a)
    {
        int n = a.size() ;
        
        for(int i=0,j=n-1;i<=j;i++,j--)
        {
            if(a[i]!=a[j])
                return 0;
        }
        return 1;
    }
    
public:
    bool isStrictlyPalindromic(int n) {
        
        string k;
        
        for(int i=2;i<=n-2;i++)
        {
            k = change(n,i);
            if(!ispali(k))
                return 0;
        }
        return 1;
        
        
    }
};