class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        
        int n = a.size();
        sort(a.begin(),a.end());
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto i:a)
            m[i]++;
        
        for(int i=0;i<n;i++)
        {
            if(m[a[i]]!=0)
            {
                m[a[i]]--;
                if(m[a[i]*2]!=0)
                {
                    ans.push_back(a[i]);
                    m[a[i]*2]--;
                }
                else
                    return {};
            }
        }
        return ans;
        
    }
};