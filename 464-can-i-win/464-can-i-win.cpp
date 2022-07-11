class Solution {
    
    
    bool recursion(int val,int sum,int t,unordered_map<int,bool> &dp,vector<int> &num)
    {
        int n = num.size(),f=0;
        if(sum>=t)
            return false;
        if(dp.count(val))
            return dp[val];
        
        for(int i=0;i<n;i++)
        {
            if(num[i]==0)
            {
                num[i]=1;
                val += pow(2,i);
                sum += (i+1);
                if(!recursion(val,sum,t,dp,num))
                    f=1;
                val -= pow(2,i);
                sum -= (i+1);
                num[i] = 0;
                if(f==1) 
                    break;
            }
        }
        if(f==1)
        {
            dp[val] = true;
            return true;
        }
        
        dp[val] = false;
        return false;
        
    }
    
    
public:
    bool canIWin(int n, int t) {
        
        if(t==0)
            return true;
        vector<int> num(n,0);
        
        unordered_map<int,bool> dp;
        
        int sum = (n*(n+1))/2;
        
        if(sum<t)
        return 0;
        
        if(sum==t)
        {
            if(n%2==0)
                return 0;
            return 1;
        }
       
        bool ans = recursion(0,0,t,dp,num);
        
        return ans;
        
    }
};