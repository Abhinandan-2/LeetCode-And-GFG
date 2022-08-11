class Solution {
public:
    int findLucky(vector<int>& a) {
        
        unordered_map<int,int> m;
        for(auto i:a)
            m[i]++;
        int ans = -1;
        for(auto i:m)
        {
            if(i.first==i.second)
                ans = max(ans,i.first);
        }
        
        return ans;
        
    }
};