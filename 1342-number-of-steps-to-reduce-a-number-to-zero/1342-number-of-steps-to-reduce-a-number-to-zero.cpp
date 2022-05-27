class Solution {
public:
    int numberOfSteps(int n) {
        int ans=0;
        if(n==0)
            return 0;
        while(n!=1)
        {
            if(n%2==0)
                ans++;
            else
                ans+=2;
            n/=2;
        }
        ans++;
        return ans;
        
        
    }
};