class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        
        int n = a.size() ,  m = a[0].size();
        vector<int> help(m+1,0);
        for(int i=0;i<n;i++)
             a[i].insert(a[i].begin(),0);
        a.insert(a.begin(),help);
        
        n = a.size();
        m = a[0].size();
        int ans =0,h,k1;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j] += (a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
        
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        
        unordered_map<int,int> mp;
        for(int i=1;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                mp[0] = 1;
                for(int k=1;k<n;k++)
                {
                    h = a[k][j]-a[k][i-1];
                    k1 = h-t;
                    if(mp.count(k1))
                        ans += mp[k1];
                    mp[h]++;
                }
                mp.clear();
            }
        }
        
        return ans;
        
        
        
        
    }
};