class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& a) {
        
        int n = a.size();
        unordered_map<int,int> m;
        for(auto i:a)
            m[i]++;
        priority_queue<pair<int,int>> q;
        pair<int,int> p,h;
        for(auto i:m)
        {
            q.push({i.second,i.first});
        }
        vector<int> ans;
        p = q.top();
        q.pop();
        ans.push_back(p.second);
        while(!q.empty())
        {
            h = q.top();
            q.pop();
            ans.push_back(h.second);
            if(p.first!=1)
            q.push({p.first-1,p.second});
            p = h;
        }
        return ans;
        
    }
};