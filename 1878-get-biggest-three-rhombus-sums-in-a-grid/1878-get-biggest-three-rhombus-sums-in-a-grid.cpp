class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) {
        
        int n = a.size() , m1 = a[0].size(),h,k,sz,sum=0;
        unordered_map<int,int> m;
        priority_queue<int,vector<int>,greater<int>> q;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m1;j++)
            {
                if(q.empty())
                {
                    q.push(a[i][j]);
                    m[a[i][j]]++;
                }
                else
                {
                    if(m[a[i][j]]==0)
                    {
                        q.push(a[i][j]);
                        m[a[i][j]]++;
                    }
                }
                if(q.size()>3)
                {
                    h = q.top();
                    q.pop();
                    m[h]--;
                }
            }
        
        for(int s=1;s<=min((n-1)/2,(m1-1)/2);s++)
        {
            for(int i=0;i<n-(s*2);i++)
            {
                for(int j=s;j<m1-s;j++)
                {
                    sz = s;
                    h = i;
                    k = j;
                    sum =0;
                    while(sz--)
                        sum += a[++h][--k];
                    sz = s;
                    while(sz--)
                        sum += a[++h][++k];
                    sz = s;
                    while(sz--)
                        sum += a[--h][++k];
                    sz = s;
                    while(sz--)
                        sum += a[--h][--k];
                    if(m[sum]==0)
                    {
                        q.push(sum);
                        m[sum]++;
                    }
                    if(q.size()>3)
                    {
                        h = q.top();
                        q.pop();
                        m[h]--;
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};