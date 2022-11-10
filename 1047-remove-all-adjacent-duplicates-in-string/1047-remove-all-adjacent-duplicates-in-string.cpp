class Solution {
public:
    string removeDuplicates(string a) {
        
        stack<char> s;
        char c;
        string ans;
        for(int i=0;i<a.size();i++)
        {
            if(s.empty())
                s.push(a[i]);
            else if(a[i]==s.top())
            {
                s.pop();
            }
            else
                s.push(a[i]);
        }
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};