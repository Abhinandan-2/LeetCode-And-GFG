class Solution {
public:
    int numMatchingSubseq(string a, vector<string>& w) {
        
        int n = a.size();
        
        map<char,vector<int>> m;
        
        for(int i=0;i<n;i++)
            m[a[i]].push_back(i);
        
        int ans =0,k,f,h ;
        
        for(int i=0;i<w.size();i++)
        {
            k = -1;
            f=0;
            for(int j=0;j<w[i].size();j++)
            {
                vector<int> &v = m[w[i][j]];
                h = upper_bound(v.begin(),v.end(),k)-v.begin();
                if(h==v.size())
                {
                    f=1;
                    break;
                }
                k = v[h];
            }
            if(f==0)
                ans++;
        }
        
        return ans;
    }
};