class Solution {
public:
    int fib(int n) {
        
        int c , pre , fu;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        c = 1;
        pre =0 ;
        for(int i=2;i<=n;i++)
        {
            fu = c+pre;
            pre = c;
            c = fu;
        }
        
        return fu;
        
    }
};