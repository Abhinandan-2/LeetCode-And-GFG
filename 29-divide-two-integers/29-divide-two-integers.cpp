class Solution {
public:
    int divide(int d1, int b1) {
        
        long long ans =0,h,d,b ;
        d = d1;
        b = b1;
        int f=0;
        if(d<0&&b<0)
        {
            d = abs(d);
            b = abs(b);
        }
        else if(d<0)
        {
            d = abs(d);
            f=1;
        }
        else if(b<0)
        {
            f =1;
            b = abs(b);
        }
        
        
        if(d>1000)
        {
            int c=0;
            long long b2 = 0;
            while(b2<1000)
            {
                b2 += b;
                c++;
            }
            while(d>=b2)
            {
                d -= b2;
                ans++;
            }
            h = ans;
            c--;
            while(c--)
                ans += h;
                
            
            while(d>=b)
            {
                d -= b;
                ans++;
            }
            
        }
        else
        {
            while(d>=b)
            {
                d -= b;
                ans++;
            }
        }
        
        if(f==1)
        {
            h = ans;
            ans -= h;
            ans -= h;
        }
        
        if(ans>INT_MAX)
            return INT_MAX;
        if(ans<INT_MIN)
            return INT_MIN;
        return (int)ans;
        
        
    }
};

