#define ll long long 

class Solution {
public:
    bool isUgly(int d) {
        
    if(d==1)
    return 1;
    ll a=2,b=3,c=5;
    ll x=0,y=0,z=0,s=0,h;
    vector<ll> ans;
    ans.push_back(1);
    int n = 1;
    while(s<=d)
    {
        h = min(ans[x]*a,min(ans[y]*b,ans[z]*c));
        if(h==d)
            return 1;
        if(s!=h)
        {
            ans.push_back(h);
        }
        if(h==ans[x]*a)
            x++;
        if(h==ans[y]*b)
            y++;
        if(h==ans[z]*c)
            z++;
        s=h;
    }
    return 0;
        
    }
};