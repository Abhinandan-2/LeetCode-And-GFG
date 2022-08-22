class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
           return 0;
        
        int h = log2(n)/log2(4);
        int p = pow(4,h);
        
        if(p==n)
            return 1;
        return 0;
        
    }
};