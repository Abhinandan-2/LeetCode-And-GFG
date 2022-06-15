class Solution {
    
    static bool com(string &a,string &b)
    {
        int n = a.size() , m = b.size();
        return n<m;
    }
    
    bool is(string &a,string &b)
    {
        int n = a.size() ,  m = b.size();
        if(n+1!=m)
            return 0;
        int i=0 ,j=0,f=0;
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(f==1)
                    return 0;
                f=1;
                j++;
            }
        }
        if(i==n&&j<m)
        {
            if(f==1)
                return 0;
            return 1;
                
        }
        if(f==1)
            return 1;
        return 0;
    }
    
public:
    int longestStrChain(vector<string>& a) {
        
        int n = a.size(),ans=1;
        sort(a.begin(),a.end(),com);
        vector<int> v(n,1);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(is(a[i],a[j]))
                    v[i] = max(v[i],v[j]+1);
            }
            ans = max(ans,v[i]);
        }
        return ans;
        
    }
};