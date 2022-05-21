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
            if(extra)
            {
                p++;
                extra--;
            }
            while(p--)
                    ans.push_back(' ');
        }
        ans += a[n-1];
        return ans;
        
    }
    
    vector<string> fullJustify(vector<string>& a, int t) {
        
        
        vector<string> ans,help;
        int n = a.size() , f =0 , h , p;
        string k;
        for(int i=0;i<n;i++)
        {
            h = a[i].size();
            f += h;
            if(help.size()!=0)
                f++;
            if(f>t)
            {
                k = solve(help,t);
                ans.push_back(k);
                help.clear();
                help.push_back(a[i]);
                f = h;
            }
            else
            {
                help.push_back(a[i]);
            }
        }
        k.clear();
        for(int i=0;i<help.size();i++)
        {
            k+= help[i];
            k += " ";
        }
        while(k.size()>t)
            k.pop_back();
        while(k.size()<t)
            k.push_back(' ');
        ans.push_back(k);
        return ans;
        
    }
};