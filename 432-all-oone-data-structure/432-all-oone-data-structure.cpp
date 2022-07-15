class AllOne {
    
    map<int,int> mp;
    unordered_map<string,int> counts;
    unordered_map<int,unordered_set<string>> strings;
    int mx , mn;
    
public:
    AllOne() {
        
        mx = INT_MIN;
        mn = INT_MAX;
        
    }
    
    void inc(string key) {
        
        int val;
        if(counts.count(key))
        {
            val = counts[key];
            counts[key]++;
            unordered_set<string> &s = strings[val];
            s.erase(key);
            strings[val+1].insert(key);
            mx = max(mx,val+1);
            if(s.size()==0)
            {
                if(mn==val)
                    mn = val+1;
            }
            mp[val]--;
            if(mp[val]==0)
                mp.erase(val);
            mp[val+1]++;
        }
        else
        {
            counts[key]++;
            strings[1].insert(key);
            mx = max(mx,1);
            mn = 1;
            mp[1]++;
        }
        // cout<<mx<<" "<<mn<<endl;
        return ;
        
    }
    
    void dec(string key) {
        
        int val = counts[key];
        counts[key]--;
        if(counts[key]==0)
            counts.erase(key);
        mp[val]--;
        if(mp[val]==0)
            mp.erase(val);
        if(val!=1)
        {
            mp[val-1]++;
        }
        // for(auto i:strings)
        // {
        //     cout<<i.first<<"->";
        //     for(auto j:i.second)
        //         cout<<j<<" ";
        // }
        unordered_set<string> &s = strings[val];
        // cout<<s.size()<<" ";
        s.erase(key);
        if(val==1)
        {
            if(s.size()==0)
            {
                // mn = INT_MAX;
                if(mx==1)
                {
                    mx = INT_MIN;
                    mn = INT_MAX;
                }
                else
                {
                    mn = (*mp.begin()).first;
                }
            }
        }
        else
        {
            strings[val-1].insert(key);
            mn = min(mn,val-1);
            // cout<<s.size()<<" ";
            if(s.size()==0)
            {
                if(mx==val)
                    mx = mx-1;
            }
        }
        // cout<<mx<<" "<<mn<<endl;
        return ;
         
    }
    
    string getMaxKey() {
        
        if(mx==INT_MIN)
            return "";
        return (*strings[mx].begin());
        
    }
    
    string getMinKey() {
        
        if(mn==INT_MAX)
            return "";
        return (*strings[mn].begin());
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */