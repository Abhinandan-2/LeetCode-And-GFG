class Solution {
public:
    int longestValidParentheses(string a) {
        
        int n = a.size(),h,k;
        stack<int> s;
        s.push(0);
        int ans =0 ;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(')
                s.push(0);
            else
            {
                if(s.size()==1)
                {
                    h = s.top();
                    ans = max(h,ans);
                    s.pop();
                    s.push(0);
                }
                else
                {
                    h = s.top();
                    s.pop();
                    k = s.top();
                    s.pop();
                    s.push(k+h+2);
                }
            }
        }
        
        while(!s.empty())
        {
            ans = max(ans,s.top());
            s.pop();
        }
        
        return ans;
        
        
        
    }
};