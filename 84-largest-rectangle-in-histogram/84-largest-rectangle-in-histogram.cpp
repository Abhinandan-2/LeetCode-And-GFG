class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        
    int n = a.size();
    stack<int> s;
    int ans=0,h,w,st;
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&a[s.top()]>a[i])
        {
            h = s.top();
            s.pop();
            st = s.empty() ? 0:s.top()+1;
            w = (i-st);
            h = a[h];
            ans = max(ans,w*h);
        }
        s.push(i);
    }

    while(!s.empty())
    {
        h = s.top();
        s.pop();
        st = s.empty() ? 0:s.top()+1;
        w = (n-st);
        h = a[h];
        ans = max(ans,w*h);
    }

    return ans;

    }
};