class Solution {
public:
    
    bool call(string a)
    {
         int n =a.size() , c = 0,s=0 ;
        
        
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(')
                s++;
            else if(a[i]==')')
            {
                if(s==0&&c==0)
                    return 0;
                if(s==0)
                    c--;
                else
                    s--;
            }
            else
                c++;
        }
          if(c>=s)
            return 1;;
        return 0;
        
    }
    
    bool checkValidString(string a) {
        
       int n = a.size();
        if(!call(a))
            return 0;
        reverse(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(')
                a[i]=')';
            else if(a[i]==')')
                a[i] = '(';
        }
        
        return call(a);
      
        
    }
};