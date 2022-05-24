class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int t) {
        
        int n = a.size() , ts =0 , te =0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<t)
                ts++;
            if(a[i]==t)
                te++;
        }
        
        vector<int> ans;
        
        while(te--)
        {
            ans.push_back(ts);
            ts++;
        }
        return ans;
        
        
    }
};