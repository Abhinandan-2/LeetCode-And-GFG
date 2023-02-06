class Bank {
    vector<long long> a;
    int n;
public:
    Bank(vector<long long>& v) {
        a = v;
        n = v.size();
    }
    
    bool transfer(int a1, int a2, long long m) {
        
        if(a1>n||a1<1||a2>n||a2<1) return 0;
        if(a[a1-1]<m) return 0;
        a[a1-1]-=m;
        a[a2-1]+=m;
        return 1;
        
    }
    
    bool deposit(int acc, long long m) {
        
        if(acc>n||acc<1) return 0;
        
        a[acc-1]+=m;
        return 1;
        
    }
    
    bool withdraw(int acc, long long m) {
        
        if(acc>n||acc<1) return 0;
        if(a[acc-1]<m) return 0;
        a[acc-1]-=m;
        return 1;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */