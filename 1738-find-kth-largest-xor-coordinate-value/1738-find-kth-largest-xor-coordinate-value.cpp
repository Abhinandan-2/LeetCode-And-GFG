class Solution {
public:
    int kthLargestValue(vector<vector<int>>& a, int k) {
        
        int n = a.size() , m = a[0].size();
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(a[0][0]);
        for(int i=1;i<m;i++)
        {
            a[0][i] ^= a[0][i-1];
            q.push(a[0][i]);
            if(q.size()>k)
                q.pop();
        }
        
        for(int i=1;i<n;i++)
        {
            a[i][0] ^= a[i-1][0];
            q.push(a[i][0]);
            if(q.size()>k)
                q.pop();
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j] ^= a[i-1][j];
                a[i][j] ^= a[i][j-1];
                a[i][j] ^= a[i-1][j-1];
                q.push(a[i][j]);
                if(q.size()>k)
                    q.pop();
            }
        }
        return q.top();
    }
};