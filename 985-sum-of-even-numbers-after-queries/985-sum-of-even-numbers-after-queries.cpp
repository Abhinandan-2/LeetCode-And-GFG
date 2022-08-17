class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        
        int  n = a.size();
        
        vector<int> ans;
        
        int sum =0;
        
        for(auto i:a)
            if(i%2==0)
                sum+=i;
        
        for(int i=0;i<q.size();i++)
        {
            if(a[q[i][1]]%2==0)
                sum -= a[q[i][1]];
            
            a[q[i][1]] += q[i][0];
            
            if(a[q[i][1]]%2==0)
                sum += a[q[i][1]];
            ans.push_back(sum);
            
        }
        
        return ans;
        
    }
};