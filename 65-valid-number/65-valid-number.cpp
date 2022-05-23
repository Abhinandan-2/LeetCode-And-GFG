class Solution {
public:
    
    bool isInteger(string a)
    {
        int n = a.size();
        if(n==1)
        {
            if(a[0]>=48&&a[0]<=57)
                return 1;
            return 0;
        }
        
        for(int i=1;i<n;i++)
        {
            if(!(a[i]>=48&&a[i]<=57))
                return 0;
        }
        if((a[0]>=48&&a[0]<=57)||a[0]=='+'||a[0]=='-')
            return 1;
        return 0;
        
    }
    
    bool isDecimal(string a)
    {
        int n = a.size();
        if(n==1)
            return 0;
        int dotFlag = 0,i=0;
        if(a[0]=='+'||a[0]=='-')
        {
            if(n==2)
                return 0;
            i++;
        }
        while(i<n)
        {
            if(dotFlag==1)
            {
                if(!(a[i]>=48&&a[i]<=57))
                    return 0;
            }
            else
            {
                if(a[i]=='.')
                    dotFlag=1;
                else
                {
                    if(!(a[i]>=48&&a[i]<=57))
                        return 0;
                }
            }
            i++;
        }
        
        return 1;
    }
    
    bool isNumber(string a) {
        
        int n = a.size() , Eindex = -1;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='e'||a[i]=='E')
            {
                Eindex = i;
                break;
            }
        }
        if(Eindex==-1)
        {
            if(isInteger(a))
                return 1;
            if(isDecimal(a))
                return 1;
            return 0;
        }
        if(Eindex==n-1||Eindex==0)
            return 0;
        string h = a.substr(Eindex+1,n-1-Eindex);
        string k = a.substr(0,Eindex);
        if(isInteger(h))
        {
            if(isInteger(k)||isDecimal(k))
                return 1;
            return 0;
        }
        
        return 0;
        
    }
};