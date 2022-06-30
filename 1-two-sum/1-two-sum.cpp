class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        
          int n = a.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i] = {a[i],i};
        }
        
        sort(v.begin(),v.end());
      
        for(int i=0,j=n-1;i<j;)
        {
            if(v[i].first+v[j].first==t)
                return {v[i].second,v[j].second};
            if(v[i].first+v[j].first>t)
                j--;
            else
                i++;
        }
        
        return {};
        
    }
};