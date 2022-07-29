class Solution {
public:
    string reverseParentheses(string a) {
        
        int n = a.size(),h;
        unordered_map<int,int> m;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(')
            {
                s.push(i);
            }
            else if(a[i]==')')
            {
                h = s.top();
                s.pop();
                m[i] = h;
                m[h] = i;
            }
        }
        
        string ans;
        int i=0,f=0;
        while(i<n)
        {
            if(a[i]=='(')
            {
                if(f==0)
                {
                    i = m[i];
                    f=1;
                    i--;
                }
                else
                {
                    i= m[i];
                    f=0;
                    i++;
                }
            }
            else if(a[i]==')')
            {
                if(f==0)
                {
                    i = m[i];
                    f=1;
                    i--;
                }
                else
                {
                    i = m[i];
                    f=0;
                    i++;
                }
            }
            else
            {
                ans.push_back(a[i]);
                if(f==0)
                    i++;
                else
                    i--;
            }
                
        }
        
        return ans;
        
        
        
    }
};