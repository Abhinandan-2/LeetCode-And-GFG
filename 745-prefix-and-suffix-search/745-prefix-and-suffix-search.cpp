class WordFilter {
    
    unordered_map<string,int> m;
    
public:
    WordFilter(vector<string>& a) {
        
        int n = a.size(),k1;
        string h1 ,h2;
        for(int i=0;i<n;i++)
        {
            int k1 = a[i].size();
            for(int j=1;j<=k1;j++)
            {
                h1 = a[i].substr(0,j);
                for(int k=0;k<k1;k++)
                {
                    h2 = a[i].substr(k,k1-k);
                    m[h1+" "+h2] = i;
                }
            }
        }
        
        
    }
    
    int f(string pre, string suf) {
        
        if(m.count(pre+" "+suf))
            return m[pre+" "+suf];
        return -1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */