class Solution {
public:
    int longestCycle(vector<int>& a) {
        
        int n = a.size(),ans =-1 ,c=0,h;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
            v[i] = {-1,-1};
        for(int i=0;i<n;i++)
        {
            if(v[i].first==-1)
            {
                h = i ;
                c =1;
                while(h!=-1&&v[h].first==-1)
                {
                    v[h] = {c,i};
                    h = a[h];
                    c++;
                }
                if(h!=-1&&v[h].second==i)
                    ans = max(ans,c-v[h].first);
            }
        }
        
        
        return ans;
        
    }
};