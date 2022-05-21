class Solution {
public:
    
    void call(string a,string b,vector<string> &ans,int i,int c)
    {
        int n = a.size();
        //cout<<b<<endl;
        if(i==n&&c==4)
        {
            ans.push_back(b);
            return ;
        }
        if(c==4||i==n)
            return ;
            
        if(a[i]=='0')
        {
            b.push_back(a[i]);
            if(c!=3)
            b.push_back('.');
            call(a,b,ans,i+1,c+1);
            if(c!=3)
            b.pop_back();
            b.pop_back();
            return ;
        }
        string h;
        int k,p;
        for(int j=i;j<min(n,i+3);j++)
        {
            h = a.substr(i,j-i+1);
            k = stoi(h);
            if(k>0&&k<=255)
            {
                b+=h;
                if(c!=3)
                b.push_back('.');
                call(a,b,ans,j+1,c+1);
                if(c!=3)
                b.pop_back();
                p = j-i+1;
                while(p--)
                    b.pop_back();
                    
            }
        }
        return ;
        
    }
    
    
    vector<string> restoreIpAddresses(string a) {
        
        int n = a.size();
        
        vector<string> ans;
        string b;
        
        call(a,b,ans,0,0);
        return ans;
        
    }
};