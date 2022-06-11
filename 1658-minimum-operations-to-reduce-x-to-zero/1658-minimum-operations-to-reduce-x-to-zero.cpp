class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        
        int n = a.size(),t;
        int sum = accumulate(a.begin(),a.end(),0);
        if(x>sum)
            return -1;
        if(x==sum)
            return n;
        unordered_map<int,int> m,b;
        vector<int> v =a , p =a ;
        m[v[0]] = 0;
        for(int i=1;i<n;i++)
        {
            v[i] += v[i-1];
            m[v[i]] = i;
        }
        b[p[n-1]] = 0;
        for(int i=n-2;i>=0;i--)
        {
            p[i] += p[i+1];
            b[p[i]] = (n-1-i);
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]>x)
                break;
            if(v[i]==x)
                ans = min(ans,i+1);
            else
            {
                t = x-v[i];
                if(b.count(t))
                    ans = min(ans,i+1+b[t]+1);
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(p[i]>x)
                break;
            if(p[i]==x)
                ans = min(ans,n-i);
            else
            {
                t = x-p[i];
                if(m.count(t))
                    ans = min(ans,n-i+m[t]+1);
            }
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;   
    }
};