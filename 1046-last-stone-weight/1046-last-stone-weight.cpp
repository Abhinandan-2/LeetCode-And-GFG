class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        
        int n= a.size(),p,s,h;
        priority_queue<int> q;
        for(int i=0;i<n;i++)
            q.push(a[i]);
        
        while(q.size()>1)
        {
            p = q.top();
            q.pop();
            s = q.top();
            q.pop();
            p -= s;
            if(p!=0)
                q.push(p);
        }
        
        if(q.empty())
            return 0;
        return q.top();
        
    }
};