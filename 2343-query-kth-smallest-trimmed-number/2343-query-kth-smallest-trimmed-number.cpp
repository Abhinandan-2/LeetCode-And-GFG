class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& t) {
        
        
        vector<int> ans; // For storing final output
        priority_queue<pair<string,int>> q;  // For finding kth smallest string
        
        
        int res , len;
        
        string h;
        
        for(int i=0;i<t.size();i++)   // Traverse the query array.
        {
            len = a[0].size();    // Length is equal 
            for(int j=0;j<a.size();j++)
            {
                
                h = a[j].substr(len-t[i][1],t[i][1]);  // Sub string after trim
                
                q.push({h,j});             // Pushing into Max heap (Queue)
                
                if(q.size()>t[i][0])    // If q size greater than k, pop element from the queue. To get the Kth smallest element on top of the queue.
                    q.pop();
            }
            
            res  = q.top().second;  // Kth smallest element index.
            
            while(!q.empty())   // Empty the queue.
                q.pop();
             ans.push_back(res);  // Push in output array.
        }
        
        return ans;
        
        
    }
};
