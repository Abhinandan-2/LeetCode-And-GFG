class Solution {
public:
    
    
    string mul(string a,int b)
    {
        if(b==0)
            return "0";
        int c =0 , h ;
        reverse(a.begin(),a.end());
        string ans;
        for(int i=0;i<a.size();i++)
        {
            h  = ((a[i]-48)*b)+c;
            c = h/10;
            h %= 10;
            ans.push_back(h+48);
        }
        
        if(c)
          ans.push_back(c+48);  
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
    string sum(string a,string b)
    {
        int n = a.size() , m = b.size() ,c =0 , h ,i=0,j=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        while(i<n&&j<m)
        {
            h = (a[i]-48)+(b[j]-48)+c;
            c = h/10;
            h %= 10;
            ans.push_back(h+48);
            i++;
            j++;
        }
        
        while(i<n)
        {
            h = (a[i]-48)+c;
            c = h/10;
            h %= 10;
            ans.push_back(h+48);
            i++;
        }
        
        while(j<m)
        {
            h = (b[j]-48)+c;
            c = h/10;
            h %= 10;
            ans.push_back(h+48);
            j++;
        }
        
        if(c)
            ans.push_back(c+48);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
    
    string multiply(string a, string b) {
        
        
        if(a=="0"||b=="0")
            return "0";
        
        string ans = "",h;
        
        reverse(b.begin(),b.end());
        int k;
        for(int i=0;i<b.size();i++)
        {
            h = mul(a,b[i]-48);
            
            k = i;
            while(k--)
                h.push_back('0');
            
            //cout<<h<<endl;
            ans = sum(ans,h);
        }
        
        return ans;
        
    }
};