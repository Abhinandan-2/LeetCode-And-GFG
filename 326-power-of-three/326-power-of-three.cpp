class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)
            return 0;
        
        int p = log2(n)/log2(3);
        int h = pow(3,p);
        if(h==n)
            return 1;
        return 0;
        
    }
};