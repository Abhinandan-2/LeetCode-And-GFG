class Solution {
public:
    int findTheLongestSubstring(string a) {
        
        int n = a.size(),ans=0;
        map<vector<int>,int> m;
        vector<int> v(5,0);
        m[v]=-1;
        for(int i=0;i<n;i++)
        {
            // cout<<a[i]<<" ";
            if(a[i]=='a')
                v[0]++;
            else if(a[i]=='e')
                v[1]++;
            else if(a[i]=='i')
                v[2]++;
            else if(a[i]=='o')
                v[3]++;
            else if(a[i]=='u')
                v[4]++;
            // cout<<1<<" ";
            for(int j=0;j<5;j++)
                v[j] %= 2;
            if(m.count(v))
                ans = max(ans,i-m[v]);
            else
                m[v] = i;
            // cout<<ans<<endl;
        }
        
        return ans;
        
    }
};