class Solution {
public:
    int mirrorReflection(int n, int k) {
        
        if(k==n)
            return 1;
        int dir =0 , hi =k ,i=1;
        
        while(i)
        {
            if(hi==0)
            {
                if(i%2==0)
                    return -1;
                return 0;
            }
            if(hi==n)
            {
                if(i%2==0)
                    return 2;
                return 1;
            }
            if(dir==0)
                hi += k;
            else
                hi-= k;
            if(hi<0)
            {
                hi *= -1;
                dir++;
                dir %= 2;
            }
            else if(hi>n)
            {
                hi = n-(hi-n);
                dir++;
                dir %= 2;
            }
            i++;
        }
        
        return -1;
        
    }
};