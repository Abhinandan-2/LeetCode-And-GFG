class Skiplist {
    
    unordered_map<int,int> m;
    
public:
    Skiplist() {
        
    }
    
    bool search(int target) {
        
        return m.count(target);
        
    }
    
    void add(int num) {
        
        m[num]++;
        return ;
        
    }
    
    bool erase(int num) {
        
        if(!m.count(num))
            return 0;
        m[num]--;
        if(m[num]==0)
            m.erase(num);
        return 1;
        
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */