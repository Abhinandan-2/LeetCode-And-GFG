class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& a) {
        
        int n = a.size(),ans =0 ,i=0;
        
        priority_queue<int> q;
        
        while(s<t)
        {
            while(i<n&&a[i][0]<=s)
            {
                q.push(a[i][1]);
                i++;
            }
            if(q.empty())
                return -1;
            s += q.top();    // Use the station which has more fuel
            q.pop();
            ans++;
            
        }
        return ans;
    }
};