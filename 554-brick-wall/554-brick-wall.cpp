#define ll long long

class Solution {
public:
    int leastBricks(vector<vector<int>>& a) {
        
        int n = a.size();
        ll maxSum=0 , match , nextVal;
        
        for(int i=0;i<a[0].size();i++)
            maxSum += a[0][i];
        
        set<pair<ll,int>> s;
        pair<ll,int> p;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            if((ll)a[i][0]!=maxSum)
                s.insert({(ll)a[i][0],i});
        }
        
        int ans = INT_MAX ,res =0;
        
        while(!s.empty())
        {
            p = *s.begin();
            match = p.first;
            res = 1;
            s.erase(s.begin());
            nextVal = p.first+a[p.second][m[p.second]+1];
            if(nextVal!=maxSum){
                s.insert({nextVal,p.second});
                m[p.second]++;
            }
            while(s.size()>0&&(*s.begin()).first==match)
            {
                res++;
                p = (*s.begin());
                s.erase(s.begin());
                nextVal = p.first+a[p.second][m[p.second]+1];
                if(nextVal!=maxSum){
                    s.insert({nextVal,p.second});
                    m[p.second]++;
                }
            }
            
            ans = min(ans,n-res);
        }
        
        if(ans==INT_MAX)
            return n;
        return ans;
        
    }
};