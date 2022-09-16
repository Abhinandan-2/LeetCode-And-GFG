class Solution {
    
    int call(vector<int> &arr,vector<int> &mul,int start,int index,vector<vector<int>> &dp)
    {
        int len = arr.size() , m = mul.size();
        if(index>=m) return 0;
        if(dp[index][start]!=INT_MIN)
            return dp[index][start];
        
        int end = len-index+start-1;
        int first = arr[start]*mul[index], second = arr[end]*mul[index];
        int res1 = call(arr,mul,start+1,index+1,dp);
        int res2 = call(arr,mul,start,index+1,dp);
        
        
        int ans = max(res1+first,res2+second);
        
        dp[index][start] = ans;
        return ans;
          
    }
    
public:
    int maximumScore(vector<int>& arr, vector<int>& mul) {
        
        int len = mul.size();
        vector<vector<int>> dp(len,vector<int> (len,INT_MIN));
        
        int ans = call(arr,mul,0,0,dp);
        
        return ans;      
    }
};