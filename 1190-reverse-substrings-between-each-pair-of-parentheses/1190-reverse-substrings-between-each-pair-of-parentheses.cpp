class Solution {
public:
    string reverseParentheses(string a) {
        
        stack<string> s;
        string ans , h ,k ;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='(')
            {
                s.push(h);
                h.clear();
            }
            else if(a[i]==')')
            {
                reverse(h.begin(),h.end());
                k = s.top();
                s.pop();
                k += h;
                h = k;
            }
            else
            {
                h += a[i];
            }
            // cout<<h<<" "<<k<<endl;
        }
        
        return h;
        
    }
};