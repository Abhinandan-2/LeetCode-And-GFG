class Solution {
public:
    
    static bool com(int &a,int &b)
    {
        string h = to_string(a);
        string k = to_string(b);
        return h<k;
    }
    
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i] = i+1;
        sort(ans.begin(),ans.end(),com);
        return ans;
    }
};