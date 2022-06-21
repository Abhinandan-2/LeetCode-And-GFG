class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        
        int n= a.size();
        
        vector<int> v(n);
        v[0]= 0 ;
        
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]<=0)
                v[i] = 0;
            else
                v[i] = a[i]-a[i-1];   
        }
        priority_queue<int> q;
        int h;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
                continue;
            if(b>=v[i])
            {
                b-=v[i];
                q.push(v[i]);
            }
            else
            {
                if(l==0)
                    return i-1;
                if(q.empty())
                    l--;
                else
                {
                    l--;
                    h = q.top();
                    if(v[i]<h)
                    {
                        q.pop();
                        b += (h-v[i]);
                        q.push(v[i]);
                    }
                        
                }

            }
        }
        
        return n-1;
        
        
        
    }
};