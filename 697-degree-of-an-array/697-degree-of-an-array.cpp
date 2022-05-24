class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        
        int n = a.size();
        unordered_map<int,int> last,first,m;
        vector<int> count;
        
        for(int i=0;i<n;i++)
        {
            last[a[i]]= i;
            m[a[i]]++;
        }
        for(int i=n-1;i>=0;i--)
        {
            first[a[i]]=i;
        }
        int mx = -1;
        for(auto i:m)
        {
            if(i.second>=mx)
            {
                if(i.second>mx)
                {
                    count.clear();
                    mx = i.second;
                }
                count.push_back(i.first);
            }
        }
        
        int ans = INT_MAX,h;
        
        for(int i=0;i<count.size();i++)
        {
            
            h = last[count[i]]-first[count[i]]+1;
            //cout<<count[i]<<" "<<last[count[i]]<<" "<<first[count[i]]<<endl;
            ans = min(ans,h);
        }
        
        return ans;
        
        
    }
};