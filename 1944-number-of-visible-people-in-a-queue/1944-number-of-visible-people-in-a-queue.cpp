class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        
        int n = a.size();
        
        stack<pair<int,int>> s;
        pair<int,int> p;
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&a[s.top().first]<=a[i])
            {
                p = s.top();
                ans[p.first] = p.second+1;
                s.pop();
                if(!s.empty())
                {
                    p = s.top();
                    s.pop();
                    s.push({p.first,p.second+1});
                }
            }
            s.push({i,0});
        }
        while(!s.empty())
        {
            p = s.top();
            ans[p.first] = p.second;
            s.pop();
            if(!s.empty())
            {
                p = s.top();
                s.pop();
                s.push({p.first,p.second+1});
            }
        }
        ans[n-1]=0;
        
        return ans;
        
        
        
    }
};