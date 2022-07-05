class Solution {
public:
    int uniquePaths(int n, int m) {
        
        n--;
        m--;
        
        int cal1 =1 , cal2 =1 ,total = n+m,gcd;
        
        if(n<m)
            swap(n,m);
        
        for(int i=m;i>=1;i--)
        {
            cal1 *= i;
            cal2 *= total;
            total--;
            gcd = __gcd(cal1,cal2);
            cal1/=gcd;
            cal2/=gcd;
        }
        int ans = cal2/cal1;
        return ans;
        
        
    }
};