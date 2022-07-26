class Solution {
public:
    int largestValsFromLabels(vector<int>& a, vector<int>& b, int mxLen, int t) {
        
        int n = a.size();
        unordered_map<int,int> mxLable;
        int mxValue =0 ;
        priority_queue<pair<int,int>> q;
        pair<int,int> p;
        for(int i=0;i<n;i++)
            q.push({a[i],b[i]});
        
        while(!q.empty()&&mxLen--)
        {
            p = q.top();
            q.pop();
           
            if(mxLable[p.second]>=t)
            {
                mxLen++;
                continue;
            }
             // cout<<p.first<<" "<<p.second<<endl;
            mxValue += p.first;
            mxLable[p.second]++;
        }
        
        return mxValue;
        
        
        
        
    }
};