class Solution {
public:
    bool isHappy(int n) {
        
        if(n<10)
        {
            if(n==1||n==7)
                return true;
            return false;
        }
        
        int h =0;
        while(n)
        {
            h += (n%10)*(n%10);
            n/=10;
        }
        
        return isHappy(h);
        
    }
};