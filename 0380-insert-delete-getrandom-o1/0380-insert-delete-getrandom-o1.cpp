class RandomizedSet {
    
    unordered_map<int,int> m;
    vector<int> v;
    
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m.count(val))
            return 0;
       
        v.push_back(val);
        m[val]= v.size()-1;
        
        return 1;
        
    }
    
    bool remove(int val) {
        
        if(!m.count(val))
            return 0;
        
        int h = m[val];
        int n = v.size();
        swap(v[h],v[n-1]);
        m[v[h]] = h;
        v.pop_back();
        m.erase(val);
        
        return 1;
        
        
        
        
    }
    
    int getRandom() {
        
        int n = v.size();
        
        int h = random()%n;
        
        return v[h];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */