class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        
        priority_queue<int> q;
        int ans =0 , p,h;
        for(auto i:a)
            q.push(i);
        
        while(k--)
        {
            p= q.top();
            q.pop();
            h = p/2;
            p -= h;
            q.push(p);
        }
        
        
        while(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
        
        return ans;
        
        
    }
};