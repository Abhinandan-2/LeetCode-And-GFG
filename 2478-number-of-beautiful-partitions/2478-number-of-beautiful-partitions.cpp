class Solution {
public:
    long long mod=1e9+7;
    long long dp[1001][1001];
    int n;
    bool isPrime(char ch){
        if(ch == '2' || ch == '3' || ch == '5' || ch == '7')
            return true;
        return false;
    }
    int solve(int i,int ml,int k,vector<int>&pos){
        if(k==0 && i == pos.size()-1) return 1;
        if(k==0 || i == pos.size()-1) return 0; 
        if(dp[i][k] != -1) return dp[i][k];
        long long ans=0;
        for(int x=i+1;x<=pos.size()-k;x++){
            if(pos[x]-pos[i] < ml) continue;
            ans=(ans+solve(x,ml,k-1,pos))%mod;
        }
        return dp[i][k]=ans%mod;
    }
    int beautifulPartitions(string s, int k, int ml) {
        n = s.size();
        if(!isPrime(s[0]) || isPrime(s[n-1])) return 0; 
        vector<int>pos;
        pos.push_back(0);
        for(int i=1;i<n-1;i++){
            if(!isPrime(s[i]) && isPrime(s[i+1])){
                pos.push_back(i+1);
            }
        }
        if(pos.size() < k) return 0; 
        pos.push_back(n);
        memset(dp , -1,sizeof dp);
        return solve(0,ml,k,pos)%mod;
    }
};