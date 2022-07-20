class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& t) {
        
        int n = a.size();
        
        int h = lower_bound(a.begin(),a.end(),t)-a.begin();
        
        a.insert(a.begin()+h,t);
        n++;
        vector<vector<int>> ans;
        int s = a[0][0] , e = a[0][1];
        // for(auto i:a)
        // {
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        for(int i=1;i<n;i++)
        {
             // cout<<s<<" "<<e;
            if(a[i][0]<=e)
                e = max(e,a[i][1]);
            else
            {
                ans.push_back({s,e});
                s = a[i][0];
                e = a[i][1];
            }
        }
       
        ans.push_back({s,e});
        
        return ans;
        
    }
};