class Solution {
public:
    string smallestNumber(string a) {
        
        int c=0 ;
        int s = 1, i=0 , n = a.size(),t=0,p;
        string ans;
       while(i<n)
       {
           if(a[i]=='I')
           {
               ans.push_back(s+48);
               s++;
               i++;
           }
           s+=t;
           while(i<n&&a[i]=='I')
           {
               ans.push_back(s+48);
               s++;
               i++;
           }
           
           c=0;
           while(i<n&&a[i]=='D')
           {
               c++;
               i++;
           }
           t=c;
           p = c;
           c += s;
           while(p--)
           {
               ans.push_back(c+48);
                   c--;
           }
           
       }
        int l = ans[ans.size()-1]-48;
        if(a[n-1]=='I')
            ans.push_back(s+48);
        else
            ans.push_back(l-1+48);
        return ans;
        
        
    }
};