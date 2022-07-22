class Solution {
public:
    string minWindow(string s, string t) {
        
         int n = t.size(),m=s.size();
     unordered_map<char,int> p,q;
     for(int i=0;i<n;i++)
     {
         p[t[i]]++;
     }
     q=p;
     int r,l,ma=-1,c=0,f=0,g,i=0;
     while(c!=n&&i<m)
     {
         if(p[s[i]])
         {
             if(q[s[i]]>0)
             {
                 if(c==0)
                    l=i;
                c++;
             }
            q[s[i]]--;
         }
         i++;
     }
     if(c!=n)
        return "";
     r=i;
     ma = r-l+1;
     g=l;
     while(l<m&&r<m)
     {
         if(f==0)
         {
             if(p[s[l]])
             {
                 if(q[s[l]]==0)
                 {
                     f=1;
                     if(ma>r-l)
                     {
                         ma = r-l;
                         g=l;
                     }
                 }
                 q[s[l]]++;
             }
             l++;
         }
         else
         {
             if(p[s[r]])
             {
                 if(q[s[r]]==1)
                 {
                     f=0;
                 }
                 q[s[r]]--;
             }
             r++;
         }
     }
     while(f==0&&l<m)
         {
             if(p[s[l]])
             {
                 if(q[s[l]]==0)
                 {
                     f=1;
                     if(ma>r-l)
                     {
                         ma = r-l;
                         g=l;
                     }
                 }
                 q[s[l]]++;
             }
             l++;
         }
         return s.substr(g,ma);
        
        
    }
};