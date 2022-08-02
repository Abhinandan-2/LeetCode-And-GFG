class Solution {
public:
    
    struct com{
        
        bool operator()(pair<int,int> &a,pair<int,int> &b)
        {
            if(a.first==b.first)
                return a.second>b.second;
            return a.first>b.first;
        }
        
    };
    
    int kthSmallest(vector<vector<int>>& a, int k) {
        
        int n = a.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,com> q;
        pair<int,int> p;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            q.push({a[i][0],i});
        }
        
        k--;
        while(k--)
        {
            p = q.top();
            q.pop();
            if(m[p.second]!=n-1)
            {
                m[p.second]++;
                q.push({a[p.second][m[p.second]],p.second});
            }
        }
        
        return q.top().first;
        
        
    }
};