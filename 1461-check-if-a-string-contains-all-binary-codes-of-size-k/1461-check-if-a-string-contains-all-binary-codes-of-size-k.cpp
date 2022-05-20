class Solution {
public:
    bool hasAllCodes(string a, int t) {
        
        unordered_map<int,int> m;
        int sum =0,n=a.size();
        if(t>n)
            return 0;
        for(int i=0;i<t;i++)
        {
            sum *= 2;
            if(a[i]=='1')
                sum++;
        }
        m[sum]++;
        int p = pow(2,t);
        for(int i=t;i<n;i++)
        {
            sum *= 2;
            if(a[i]=='1')
                sum++;
            if(a[i-t]=='1')
                sum-=p;
            m[sum]++;
        }
        if(m.size()==p)
            return 1;
        return 0;
        
        
    }
};