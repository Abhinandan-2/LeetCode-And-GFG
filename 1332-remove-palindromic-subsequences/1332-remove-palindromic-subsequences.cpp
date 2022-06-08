class Solution {
    
    bool ispali(string &a)
    {
        int n =a.size();
        for(int i=0,j=n-1;i<=j;i++,j--)
        {
            if(a[i]!=a[j])
                return 0;
        }
        return 1;
    }
    
public:
    int removePalindromeSub(string a) {
        
        if(ispali(a))
            return 1;
        return 2;
        
    }
};