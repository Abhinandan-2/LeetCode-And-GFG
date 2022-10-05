class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        
        int n= items.size(), mx = -1, m1 = q.size();
        sort(items.begin(),items.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            mx = max(mx,items[i][1]);
            m[items[i][0]] = mx;
        }
        vector<int> ans;
        for(int i=0;i<m1;i++){
            auto it = m.lower_bound(q[i]);
            if(it->first==q[i]) ans.push_back(it->second);
            else{
                if(it==m.begin()) ans.push_back(0);
                else{
                    it--;
                    ans.push_back(it->second);
                }
            }
        }
        return ans;
    }
};