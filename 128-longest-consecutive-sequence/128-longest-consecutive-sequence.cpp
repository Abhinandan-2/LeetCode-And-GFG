class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        
        int n = a.size(),ans=0,mx,mn;
        unordered_map<int,pair<int,int>> m;
        
        for(int i=0;i<n;i++)
        {
            if(!m.count(a[i]))
            {
                if(!m.count(a[i]-1)&&!m.count(a[i]+1))
                    m[a[i]] = {a[i],a[i]};
                else if(m.count(a[i]+1)&&m.count(a[i]-1))
                {
                    mx = m[a[i]+1].second;
                    mn = m[a[i]-1].first;
                    m[mn]= {mn,mx};
                    m[mx] = {mn,mx};
                    m[a[i]] = {mn,mx};
                }
                else if(m.count(a[i]+1))
                {
                    mx = m[a[i]+1].second;
                    mn = a[i];
                    m[mx] = {mn,mx};
                    m[mn] = {mn,mx};
                }
                else
                {
                    mx = a[i];
                    mn = m[a[i]-1].first;
                    m[mn] = {mn,mx};
                    m[mx]= {mn,mx};
                }
            }
            // cout<<a[i]<<"->"<<endl;
             
        
        }
        
       
        for(auto i:m)
        {
            // cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
            ans = max(ans,i.second.second-i.second.first+1);
        }
        return ans;
    }
};