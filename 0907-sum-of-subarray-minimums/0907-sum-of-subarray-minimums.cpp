class Solution {
    
    vector<int> getMin(vector<int> &a,int f)
    {
        int n = a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty())
            {
                if(f==0)
                {
                    if(a[s.top()]>a[i])
                    {
                        ans[s.top()] = i;
                        s.pop();
                    }
                    else
                        break;
                }
                else
                {
                    if(a[s.top()]>=a[i])
                    {
                        ans[s.top()] = i;
                        s.pop();
                    }
                    else
                        break;
                }
                
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ans[s.top()]=-1;
            s.pop();
        }
        return ans;
    }
    
public:
    int sumSubarrayMins(vector<int>& a) {
        
        int n= a.size();
        
        vector<int> right = getMin(a,0);
        reverse(a.begin(),a.end());
        vector<int> left = getMin(a,1);
        
        for(int i=0;i<n;i++)
        {
            if(left[i]!=-1)
                left[i] = n-1-left[i];
        }
        reverse(left.begin(),left.end());
        reverse(a.begin(),a.end());
        // for(auto i:right)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto i:left)
        //     cout<<i<<" ";
        // cout<<endl;
        
        long long ans =0 , mod =1e9+7,res=0,l,r;
        
        for(int i=0;i<n;i++)
        {
            if(right[i]==-1)
                r = (n-i-1);
            else
                r  = abs(i-right[i])-1;
            if(left[i]==-1)
                l = i;
            else
                l = abs(i-left[i])-1;
            ans = l*r+(l+r+1);
            // cout<<ans<<" ";
            ans %= mod;
            ans *= a[i];
            ans %= mod;
            res += ans;
            res %= mod;
            
        }
        return res;
        
        
    }
};