class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        
        priority_queue<int,vector<int>,greater<int>> q;
        int ans =0 , p;
        for(auto &i:a) q.push(i);
        
        while(k--){
            p =q.top();
            q.pop();
            q.push(-1*p);
        }
        
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        
        return ans;
        
        
    }
};