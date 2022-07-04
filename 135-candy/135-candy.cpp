class Solution {
public:
    int candy(vector<int>& a) {
        
        int n = a.size();
        if(n==1)
            return 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        pair<int,int> p;
        int s,f,res=0;
        for(int i=0;i<n;i++)
            q.push({a[i],i});
        
        vector<int> ans(n,-1);
        
        while(!q.empty())
        {
            p = q.top();
            q.pop();
            s = p.second;
            f = p.first;
            if(s==0)
            {
                if(ans[s+1]==-1||a[s+1]==a[s])
                    ans[s] = 1;
                else
                    ans[s] = ans[s+1]+1;
            }
            else if(s==n-1)
            {
                if(ans[s-1]==-1||a[s-1]==a[s])
                    ans[s] = 1;
                else
                    ans[s] = ans[s-1]+1;
            }
            else
            {
                if(ans[s+1]==-1&&ans[s-1]==-1)
                    ans[s] = 1;
                else if(ans[s+1]==-1)
                {
                    if(a[s-1]<a[s])
                        ans[s] = ans[s-1]+1;
                    else
                        ans[s] = 1;
                }
                else if(ans[s-1]==-1)
                {
                    if(a[s+1]<a[s])
                        ans[s] = ans[s+1]+1;
                    else
                        ans[s] = 1;
                }
                else
                {
                    if(a[s]>a[s-1]&&a[s]>a[s+1])
                        ans[s] = max(ans[s-1],ans[s+1])+1;
                    else if(a[s]>a[s-1])
                        ans[s] = ans[s-1]+1;
                    else if(a[s]>a[s+1])
                        ans[s] = ans[s+1]+1;
                    else
                        ans[s] = 1;
                }
            }
            res += ans[s];
            // cout<<s<<" "<<ans[s]<<endl;
        }
        
        // for(auto i:ans)
        //     cout<<i<<" ";
        // cout<<endl;
        
        return res;
        
    }
};