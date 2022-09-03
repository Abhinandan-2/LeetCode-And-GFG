class Solution {
    
    vector<int> makeLsp(string &a)
    {
        int n = a.size();
        vector<int> ans(n,0);
        int i =1 , len =0 ;
        while(i<n)
        {
            if(a[len]==a[i])
            {
                len++;
                ans[i] = len;
                i++;
            }
            else
            {
                if(len!=0)
                    len = ans[len-1];
                else
                {
                    ans[i] = 0;
                    i++;
                }
            }
        }
        
        return ans;
    }
    
    int isSub(string &a,string &b,vector<int> &va,vector<int> &vb)
    {
        int n = a.size(),m=b.size();
        int i=0 , j=0;
        
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(i!=0)
                    i = va[i-1];
                else
                    j++;
            }
        }
        if(i==n)
            return j-n;
        return -1;
        
    }
    
    bool check(string &a,string &b,vector<int> &vb)
    {
        int n = a.size(), m = b.size();
        
        vector<int> ans(n,0);
        int i=0,len=0;
        
        while(i<n)
        {
            if(a[i]==b[len])
            {
                len++;
                ans[i] = len;
                i++;
            }
            else
            {
                if(len!=0)
                    len = vb[len-1];
                else
                {
                    ans[i] = 0;
                    i++;
                }
            }
            // cout<<i<<" "<<len<<endl;
        }
        if(ans[n-1]==0)
            return 0;
        
        int back = n-1-ans[n-1],h =m-1;
        
        while(back>=0)
        {
            if(a[back--]!=b[h--])
                return 0;
        }
        return 1;
        
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        
        int n = a.size() , m = b.size(),pos,h,f,ans=0;
        string k;
        vector<int> va,vb;
        va = makeLsp(a);
        vb = makeLsp(b);
        
        if(m<=n)
        {
            pos = isSub(b,a,vb,va);
            if(pos!=-1)
                return 1;
            if(check(b,a,va))
                return 2;
            return -1;
        }
        
        pos = isSub(a,b,va,vb);
        // cout<<pos;
        if(pos==-1)
        {
            if(m>=2*n-1)
                return -1;
            if(check(b,a,va))
                return 2;
            return -1;
        }
        int savePos = pos-1;
        h=0;
        f=0;
        while(pos<=m-n)
        {
            k = b.substr(pos,n);
            if(k!=a)
                return -1;
            pos += n;
            ans++;
        }
        while(pos<m)
        {
            if(a[h++]!=b[pos++])
                return -1;
            if(f==0)
            {
                ans++;
                f++;
            }
        }
        h = n-1;
        f=0;
        while(savePos>=0)
        {
            if(a[h--]!=b[savePos--])
                return -1;
            if(f==0)
            {
                ans++;
                f=1;
            }
        }
        return ans;
    }
};