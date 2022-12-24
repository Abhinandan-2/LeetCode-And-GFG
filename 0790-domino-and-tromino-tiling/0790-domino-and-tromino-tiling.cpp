class Solution {
public:
    int numTilings(int n) {
        
        if(n<3)
            return n;
        int m = pow(10,9)+7;
        vector<int> a(n+1);
        a[0] = 0 ;
        a[1] = 1;
        a[2] = 2;
        a[3] = 5;
        for(int i=4;i<=n;i++)
            a[i] = (((2*a[i-1])%m)+(a[i-3]))%m;
        return a[n];
        
    }
};