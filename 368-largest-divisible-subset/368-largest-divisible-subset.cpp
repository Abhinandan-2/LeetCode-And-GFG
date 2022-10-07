class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size(),mx=0,in;
        sort(a.begin(),a.end());
        vector<pair<int,int>> v(n,{0,-1});
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--) if(a[i]%a[j]==0) if(v[j].first>=v[i].first) v[i] = {v[j].first+1,j};
            if(v[i].first==0) v[i] = {1,-1};
            mx = max(mx,v[i].first);
            if(v[i].first==mx) in = i;
        }
        while(in!=-1){
            ans.push_back(a[in]);
            in = v[in].second;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};