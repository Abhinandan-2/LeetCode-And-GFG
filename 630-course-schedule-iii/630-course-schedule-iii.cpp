class Solution {
public:
    
    static bool com(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    
    int scheduleCourse(vector<vector<int>>& a) {
        
        sort(a.begin(),a.end(),com);
        int n = a.size(), curTime  = 0;
        priority_queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            curTime += a[i][0];
            q.push(a[i][0]);
            if(curTime>a[i][1])
            {
                curTime-=q.top();
                q.pop();
            }
        }
        
        return q.size();
        
        
        
        
    }
};