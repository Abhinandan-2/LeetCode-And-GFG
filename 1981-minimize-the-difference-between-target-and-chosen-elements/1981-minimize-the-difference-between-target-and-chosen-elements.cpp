class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& a, int tar) {
        
        int n = a.size() , m =a[0].size() , dif = INT_MAX ,help,num,ans = INT_MAX;
        unordered_set<int> s,p;
        for(int j=0;j<m;j++)
        {
            if(a[0][j]>tar)
            {
                help = abs(tar-a[0][j]);
                if(help<dif)
                {
                    s.insert(a[0][j]);
                    dif = help;
                }
            }
            else
            {
                s.insert(a[0][j]);
            }
        }
        // for( auto i:s)
        //     cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                dif = INT_MAX;
                for(auto k:s)
                {
                    num = a[i][j]+k;
                    if(num>tar)
                    {
                        help = abs(tar-num);
                        if(help<dif)
                        {
                            dif = help;
                            p.insert(num);
                        }
                    }
                    else
                        p.insert(num);
                }
                
            }
            s = p;
            p.clear();
        }
        
        for(auto k:s)
        {
            ans = min(ans,abs(tar-k));
        }
        
        return ans;
         
        
    }
};