class LFUCache {
    
    int min,cap,size;
    unordered_map<int,pair<int,pair<int,list<int> ::iterator>>> val;
    unordered_map<int,list<int>> count;
    
public:
    LFUCache(int capacity) {
        
        min = -1;
        cap = capacity;
        size =0;
    }
    
    int get(int key) {
        
       if(!val.count(key)||cap==0)
           return -1;
        if(val[key].second.first==min&&count[min].size()==1)
            min++;
        
        auto it = val[key].second.second;
        
        count[val[key].second.first].erase(it);
        if(count[val[key].second.first].size()==0)
            count.erase(val[key].second.first);
        
        val[key].second.first++;
        count[val[key].second.first].push_front(key);
        auto ij = count[val[key].second.first].begin();
        val[key].second.second = ij;
        return val[key].first;
        
    }
    
    void put(int key, int value) {
        
        if(cap==0)
            return ;
        
        if(val.count(key))
        {
            val[key].first = value;
            get(key);
            return ;
        }
        
        if(size<cap)
        {
            min =1 ;
            count[1].push_front(key);
            auto it = count[1].begin();
            val[key] = {value,{1,it}};
            size++;
            return ;
        }
        
        int Key = count[min].back();
        val.erase(Key);
        count[min].pop_back();
        if(count[min].size()==0)
            count.erase(min);
        min = 1;
        count[1].push_front(key);
        auto it = count[1].begin();
        val[key] = {value,{1,it}};
        return ;
        
    }
};

/**
 * Your LFUCtache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */