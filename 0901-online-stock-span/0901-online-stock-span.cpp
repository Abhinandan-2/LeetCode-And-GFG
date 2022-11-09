class StockSpanner {
    
    stack<int> s;
    int i=0;
    vector<int> v;
    
public:
    StockSpanner() {
        
    }
    
    int next(int n) {
        
        int ans;
        
        while(!s.empty()&&v[s.top()]<=n)
            s.pop();
        
        
        if(s.empty()){
            ans = i+1;   
        }
        else{
            ans = i-s.top(); 
        }
        
        s.push(i);
        v.push_back(n);
        i++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */