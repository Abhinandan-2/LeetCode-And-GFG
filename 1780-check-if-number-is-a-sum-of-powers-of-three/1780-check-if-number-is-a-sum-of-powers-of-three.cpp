class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        int h,p;
        while(1)
        {
            h = log2(n)/log2(3);
            p = pow(3,h);
            if(p==n)
                return 1;
            if(n>=p*2)
                return 0;
            n -= p;
        }
        return 0;
        
    }
};