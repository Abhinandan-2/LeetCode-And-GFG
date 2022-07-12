class RandomizedCollection {
    
    vector<int> vec;
    unordered_map<int,unordered_set<int>> m;

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        // cout<<"insert"<<endl;
        // for(auto i:m)
        //     cout<<i.first<<" ";
        // cout<<endl;
        bool ans = m.count(val) ? false : true ;
        int n = vec.size();
        vec.push_back(val);
        
        m[val].insert(n);
        return ans;
        
    }
    
    bool remove(int val) {
        
        // cout<<"Remove"<<endl;
        bool ans = m.count(val) ? true : false;
        if(!ans)
            return false;
        
        unordered_set<int> &s = m[val];
        int pos = *s.begin();
        int n = vec.size();
        if(pos==n-1)
        {
            vec.pop_back();
            s.erase(s.begin());
            if(s.size()==0)
                m.erase(val);
            return ans;
        }
        swap(vec[pos],vec[n-1]);
        vec.pop_back();
        // if(s.size()==1)
        //     m.erase(val);
        s.erase(s.begin());
        // cout<<s.size()<<" ";
        if(s.size()==0)
            m.erase(val);
        // for(auto i:m)
        //     cout<<i.first<<" ";
        // cout<<endl;
        unordered_set<int> &p = m[vec[pos]];
        p.erase(n-1);
        p.insert(pos);
        return true;
        
        
    }
    
    int getRandom() {
        
        int n = vec.size();
        int ran = random()%n;
        return vec[ran];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */