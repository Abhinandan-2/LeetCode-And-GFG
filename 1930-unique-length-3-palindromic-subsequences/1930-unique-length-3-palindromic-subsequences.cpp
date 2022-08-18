class Solution {
public:
    int countPalindromicSubsequence(string a) {
        
        int n =a.size(),ans=0;
        unordered_map<char,int> m;
        vector<pair<int,int>> v(26,{-1,-1});
        
        for(int i=0;i<n;i++)
        {
            if(v[a[i]-97].first==-1)
                v[a[i]-97].first = i;
            else
                v[a[i]-97].second = i;
        }
        
        for(char i='a';i<='z';i++)
        {
            if(v[i-97].first!=-1)
            {
                for(int j=v[i-97].first+1;j<v[i-97].second;j++)
                {
                    if(!m.count(a[j]))
                    {
                        m[a[j]]++;
                        ans++;
                    }
                }
                m.clear();
            }
            // cout<<ans<<" ";
        }
        
        
        return ans;
        
    }
};