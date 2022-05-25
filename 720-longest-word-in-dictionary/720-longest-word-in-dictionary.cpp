class Solution {
public:
    string longestWord(vector<string>& a) {
        
        string ans;
        int n = a.size(),h,k;
        queue<string> q;
        string p;
        vector<int> v(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(a[i].size()==1)
            {
                q.push(a[i]);
                v[i]=1;
            }
        }
        
        while(!q.empty())
        {
            h = q.size();
            ans.clear();
            while(h--)
            {
                p = q.front();
                q.pop();
                if(ans.size()==0)
                    ans =p;
                else
                    ans = min(ans,p);
                //cout<<ans;
                k = p.size();
                for(int i=0;i<n;i++)
                {
                    if(v[i]==-1)
                    {
                        if(k+1==a[i].size())
                        {
                            if(p==a[i].substr(0,k))
                            {
                                
                                q.push(a[i]);
                                v[i] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans; 
        
    }
};