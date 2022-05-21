class Solution {
public:
    
    string solve(vector<string> a,int t)
    {
        int n= a.size() , f =0;
        string ans;
        if(n==1)
        {
            ans += a[0];
            while(ans.size()<t)
                ans.push_back(' ');
            return ans;
        }
        for(int i=0;i<n;i++)
            f += a[i].size();
        
        int space = t-f;
        int word = n-1;
        int fix = space/word;
        int extra = space-(fix*word),p;
        
        for(int i=0;i<n-1;i++)
        {
            p = fix;
            ans += a[i];
            while(p--)
                    ans.push_back(' ');
        }
        ans += a[n-1];
        while(extra--)
            ans.push_back(' ');
        return ans;
        
    }
    
    string reorderSpaces(string a) {
        
        
        vector<string> v;
        int n = a.size() , f =0,j=0 ;
        string h;
        for(int i=0;i<n;i++)
        {
            if(a[i]==' ')
            {
                if(f==1)
                {
                    h = a.substr(j,i-j);
                    v.push_back(h);
                    f=0;
                }
            }
            else
            {
                if(f==0)
                {
                    f=1;
                    j =i;
                }
            }
        }
        if(f==1)
        {
            h = a.substr(j,n-j);
            v.push_back(h);
        }
        
        string ans = solve(v,n);
        return ans;
        
        
    }
};