class Solution {
public:
    bool sumGame(string a) {
        
        int n = a.size();
        
        int d ,l =0,r=0 ,sum1=0 ,sum2=0 , s;
        
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(a[i]!='?')
                    sum1+=(a[i]-48);
                else
                    l++;
            }
            else
            {
                if(a[i]!='?')
                    sum2+=(a[i]-48);
                else
                    r++;
            }
        }
        
        d = sum1-sum2;
        s = l-r;
        // cout<<sum1<<" "<<sum2<<" "<<l<<" "<<r<<" "<<d<<" "<<s;
        if(s==0)
        {
            if(d==0)
                return 0;
            return 1;
        }
        
        if(d>0)
        {
            if(s>0)
                return 1;
            else
            {
                if(s%2==0)
                {
                    if((9*abs(s)/2)==abs(d))
                        return 0;
                    return 1;
                }
                else
                    return 1;
            }
        }
        else if(d<0)
        {
            if(s<0)
                return 1;
            else
            {
                if(s%2==0)
                {
                    if((9*abs(s)/2)==abs(d))
                        return 0;
                    return 1;
                }
                else
                    return 1;
            }
        }
        else
        {
            if(s==0)
                return 0;
            return 1;
        }
        
        return 0;
    }
};