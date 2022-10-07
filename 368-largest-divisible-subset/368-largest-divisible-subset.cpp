class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        
        sort(a.begin(),a.end());
        int n = a.size(),mx=0;
        vector<pair<int,int>> v(n);
        vector<int> ans;
        for(int i=0;i<n;i++){
            v[i] = {0,-1};
            for(int j=i-1;j>=0;j--)
            {
                if(a[i]%a[j]==0)
                {
                    if(v[j].first>=v[i].first)
                        v[i] = {v[j].first+1,j};
                }
            }
            if(v[i].first==0) v[i] = {1,-1};
            mx = max(mx,v[i].first);
        }
        
        int i=0;
        for(int j=n-1;j>=0;j--)
        {
            if(v[j].first==mx)
            {
                i= j;
                break;
            }
        }
        while(i!=-1)
        {
            ans.push_back(a[i]);
            i = v[i].second;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};