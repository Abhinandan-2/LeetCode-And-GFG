class RLEIterator { 
    
    vector<int> a;
    int i,n;
    
public:
    RLEIterator(vector<int>& encoding) {
        a = encoding;
        n = a.size();
        i=0;
    }
    
    int next(int t) {
        
        int ans;
        // for(auto i:a)
        //     cout<<i<<" ";
        // cout<<endl;
        while(i<n)
        {
            // cout<<i<<" ";
            if(a[i]==0)
                i+=2;
            else if(t<=a[i])
            {
                
                a[i] -= t;
                t=0;
                ans =  a[i+1];
                break;
            }
            else
            {
                t-=a[i];
                a[i] =0;
                i+=2;
            }
        }
        
        if(t==0)
            return ans;
        return -1;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */