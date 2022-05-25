#define ll long long

class Solution {
public:
    
    bool call(vector<int> &a,vector<ll> &ans,ll &t,int i)
    {
        int n = a.size(),k;
        if(i==n)
        {
            if(ans[0]==t&&ans[0]==ans[1]&&ans[0]==ans[2]&&ans[0]==ans[3])
                return 1;
            return 0;
        }
        
        for(int j=0;j<4;j++)
        {
            if(ans[j]+a[i]<=t)
           {
                k = j-1;
                while(k>=0)
                {
                    if(ans[k]==ans[j])
                        break;
                    k--;
                }
                if(k==-1)
                {
                    ans[j] += a[i];
                    if(call(a,ans,t,i+1))
                        return 1;
                    ans[j]-=a[i];
                }
            }
        }
        return 0;
        
    }
    
    bool makesquare(vector<int>& a) {
        
        int n = a.size();
        long long sum =0;
        for(auto i:a)
            sum += i;
        if(sum%4!=0)
            return 0;
        int mx = *max_element(a.begin(),a.end());
        long long t= sum/4;
        if(mx>t)
            return 0;
        sort(a.begin(),a.end(),greater<int> ());
        vector<ll> ans(4,0);
        
        return call(a,ans,t,0);
        
        
        
    }
};