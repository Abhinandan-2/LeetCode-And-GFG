class Solution {
public:
    int kthGrammar(int n, int k) {
        
        int p,h,f=0;
        
        while(k!=1)
        {
            h = log2(k)/log2(2);
            p = pow(2,h);
            if(p==k)
            {
                if(h%2==0)
                {
                    if(f%2==0)
                        return 0;
                    return 1;
                }
                else
                {
                    if(f%2==0)
                        return 1;
                    return 0;
                }
            }
            f++;
            k -= p;
        }
        
        if(f%2==0)
            return 0;
        
        return 1;
        
    }
};