class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& s, vector<vector<int>>& a, int id, int level) {
        
        
        int n = a.size(),h,p;
        vector<int> v(n,0);
        queue<int> q;
        q.push(id);
        v[id] = 1;
        while(!q.empty()&&level--)
        {
            h = q.size();
            while(h--)
            {
                p = q.front();
                q.pop();
                
                for(int i=0;i<a[p].size();i++)
                {
                    if(v[a[p][i]]==0)
                    {
                        q.push(a[p][i]);
                        v[a[p][i]] =1;
                    }
                }
            }
        }
        
        if(q.empty())
            return {};
        
        unordered_map<string,int> m;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            for(int i=0;i<s[p].size();i++)
            {
                m[s[p][i]]++;
            }
        }
        
        vector<pair<int,string>> res;
        
        for(auto i:m)
        {
            res.push_back({i.second,i.first});
        }
        
        sort(res.begin(),res.end());
        
        vector<string> ans;
        
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i].second);
        }
        
        return ans;
        
    }
};