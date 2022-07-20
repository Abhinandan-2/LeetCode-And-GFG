class MinStack {
    
    stack<int> s,p;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        s.push(val);
        if(p.empty())
            p.push(val);
        else
            p.push(min(p.top(),val));
        return ;
    }
    
    void pop() {
        
        s.pop();
        p.pop();
        
    }
    
    int top() {
        
        return s.top();
        
    }
    
    int getMin() {
        
        return p.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */