class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans =0 , mod = 1e9+7 , pow = 1,num ;
        for(int i=n;i>=1;i--){
            num = i;
            while(num){
                if(num%2!=0) ans += pow;
                num/=2;
                pow *= 2;
                ans %= mod;
                pow %= mod;
            }
        }
        return (int)ans;
    }
};