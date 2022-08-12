class Solution {
public:
    string baseNeg2(int n) {
        
        if(n==0)
            return "0";
        string ans;
        int base = -2, remainder;
        while(n!=0)
        {
            remainder = n%base;
            n /= -2;
            if(remainder==-1)      // IMP...
            {
                remainder += (-base) ;
                n++;
            }
            ans.push_back(remainder+48);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};