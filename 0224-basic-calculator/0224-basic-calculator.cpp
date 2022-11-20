#define ll long long

class Solution {
public:
    
    pair<ll,ll> call(string a,int x)
    {
        int n = a.size();
        char c = '+';
        ll h = 0 ,ans =0 ,f=-1;
        pair<ll,ll> p;
        for(int i=x;i<n;i++)
        {
            if(a[i]==')')
            {
                f = i;
                break;
            }
            if(a[i]=='+'||a[i]=='-')
            {
                if(c=='+')
                {
                    ans += h;
                    h=0;
                }
                else
                {
                    ans -= h;
                    h=0;
                }
                c = a[i];
            }
            else if(a[i]>=48&&a[i]<=57)
            {
                h *= 10;
                h += (a[i]-48);
            }
            else if(a[i]=='(')
            {
                p = call(a,i+1);
                h = p.first;
                i = p.second;
            }
        }
        if(c=='+')
        {
            ans += h;
            h=0;
        }
        else
        {
            ans -= h;
            h=0;
        }
        if(f==-1)
            f = n;
        p.first = ans;
        p.second = f;
        return p;
        
    }
    
    int calculate(string a) {
        
        pair<ll,ll> ans = call(a,0);
        return (int)ans.first;
        
        
    }
};