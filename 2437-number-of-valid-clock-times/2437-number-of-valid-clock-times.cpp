class Solution {
public:
    int countTime(string a) {
        int ans = 1;
        if(a[4]=='?') ans*=10;
        if(a[3]=='?') ans *= 6;
        if(a[1]=='?'){
            if(a[0]=='?') ans*=24;
            else if(a[0]==48||a[0]==49) ans *=10;
            else ans *= 4;
            return ans;
        }
        if(a[0]=='?'){
            if(a[1]>=52&&a[1]<=57) ans *= 2;
            else ans *= 3;
            return ans;
        }
        return ans;
        
    }
};