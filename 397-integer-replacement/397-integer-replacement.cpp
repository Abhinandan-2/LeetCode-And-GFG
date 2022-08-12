#define ll long long
class Solution {
public:
    int integerReplacement(int n) {
        
        if(n==1)
            return 0;
        unordered_map<ll,int> m;
        ll ans =-1,h,p ;
        queue<ll> q;
        q.push(n);
        m[n]++;
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                if(p==1)
                    return ans;
                if(p%2==0)
                {
                    if(!m.count(p/2))
                    {
                        q.push(p/2);
                        m[p/2]++;
                    }
                }
                else
                {
                    if(!m.count(p+1))
                    {
                        q.push(p+1);
                        m[p+1]++;
                    }
                    if(!m.count(p-1))
                    {
                        q.push(p-1);
                        m[p-1]++;
                    }
                }
                    
            }
        }
        
        return -1;
        
    }
};