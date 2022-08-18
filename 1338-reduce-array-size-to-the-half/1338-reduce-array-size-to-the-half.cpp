class Solution {
public:
    int minSetSize(vector<int>& a) {
        
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        vector<int> ans;
        for(auto i:m)
            ans.push_back(i.second);
        sort(ans.begin(),ans.end(),greater<int> ());
        n = n/2;
        int g =0,f=0;
        for(int i=0;i<ans.size();i++)
        {
            if(f>=n)
                break;
            f+=ans[i];
            g++;
        }
        
        return g;
    }
};