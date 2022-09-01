#define ll long long

class ProductOfNumbers {
    
    vector<ll> zeros;
    vector<ll> v;
    
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        
        int n = v.size();
        ll h;
        if(num==0)
        {
            zeros.push_back(n);
        }
        if(num==0||n==0||v[n-1]==0)
            v.push_back(num);
        else
        {
            h = num*v[n-1];
            v.push_back(h);
        }
        
        return ;
        
    }
    
    int getProduct(int k) {
        
        int n = v.size();
        if(k==n)
        {
            int h1 = lower_bound(zeros.begin(),zeros.end(),n-1)-zeros.begin();
            int h2 = lower_bound(zeros.begin(),zeros.end(),-1)-zeros.begin();
            if(h1!=h2)
                return 0;
            return v[n-1];
        }
        // for(auto i:v)
        //     cout<<i<<" ";
        // cout<<endl;
        ll cur = v[n-1];
        int in = n-k-1;
        ll pre = v[in];
        
        
        if(cur==0)
            return 0;
        
        
        int h1 = upper_bound(zeros.begin(),zeros.end(),n-1)-zeros.begin();
        int h2 = upper_bound(zeros.begin(),zeros.end(),in)-zeros.begin();
        // cout<<h1<<" "<<h2<<endl;
        if(h1!=h2)
            return 0;
        if(pre==0)
            return cur;
        ll ans = cur/pre;
        
        return (int)ans;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */