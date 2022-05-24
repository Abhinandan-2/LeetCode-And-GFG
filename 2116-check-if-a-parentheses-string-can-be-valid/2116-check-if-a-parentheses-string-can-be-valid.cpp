class Solution {
public:
    bool canBeValid(string a, string b) {
        
        int  n = a.size();
        if(n%2!=0)
            return 0;
        
        stack<int> s,p;
        
        for(int i=0;i<n;i++)
        {
            if(b[i]=='0')
                s.push(i);
            else
            {
                if(a[i]==')')
                {
                    if(!p.empty())
                        p.pop();
                    else if(!s.empty())
                        s.pop();
                    else
                        return 0;
                }
                else
                    p.push(i);
            }
            
        }
        
        while(!p.empty())
        {
            if(s.empty()||p.top()>s.top())
                return 0;
            s.pop();
            p.pop();
        }
        
        return 1;
        
        
        
        
        
    }
};