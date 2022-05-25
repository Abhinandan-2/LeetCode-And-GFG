class MagicDictionary {
    
    unordered_map<int,vector<string>> m;
    
    bool call(string &a,string &b)
    {
        int n = a.size(),f=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                f++;
        }
        if(f==1)
            return 1;
        return 0;
    }
    
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> a) {
        
        int h;
        for(auto i:a)
        {
            h= i.size();
            m[h].push_back(i);
        }
        return ;
        
    }
    
    bool search(string t) {
        
        int n = t.size();
        
        vector<string> &v = m[n];
        
        for(int i=0;i<v.size();i++)
        {
            if(call(t,v[i]))
                return 1;
        }
        return 0;
          
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */