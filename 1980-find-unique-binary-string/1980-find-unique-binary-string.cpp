class Solution {
    
    void inc(string &a)
    {
        int n = a.size();
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]=='0')
            {
                a[i]='1';
                return ;
            }
            else
                a[i] = '0';
        }
        return ;
    }
    
public:
    string findDifferentBinaryString(vector<string>& a) {
        
        sort(a.begin(),a.end());
        int n = a.size();
        string ans="";
        int h = n;
        while(h--)
            ans.push_back('0');
        if(a[0]!=ans)
            return ans;
        
        for(int i=1;i<n;i++)
        {
            inc(ans);
            if(ans!=a[i])
                return ans;
        }
        inc(ans);
        return ans;
        
    }
};