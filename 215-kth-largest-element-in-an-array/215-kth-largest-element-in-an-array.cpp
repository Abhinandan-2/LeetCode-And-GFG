class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        
        priority_queue<int,vector<int>,greater<int>> q;
        int n = a.size();
        for(int i=0;i<k;i++)
        {
            q.push(a[i]);
        }
        
        for(int i=k;i<n;i++)
        {
            q.push(a[i]);
            q.pop();
        }
        return q.top();
            
    }
};