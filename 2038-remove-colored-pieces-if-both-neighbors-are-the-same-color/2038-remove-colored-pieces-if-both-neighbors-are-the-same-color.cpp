class Solution {
public:
    bool winnerOfGame(string a) {
        
        int n = a.size();
        int k , f =0 , al =0 ,bo =0 ;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                k = i-f;
                if(k>=3)
                {
                    if(a[i-1]=='A')
                        al+=k-2;
                    else
                        bo+=k-2;
                }
                f = i;
            }
        }
        k = n-f;
        if(k>=3)
        {
            if(a[n-1]=='A')
                al+=k-2;
            else
                bo +=k-2;
        }
        if(al>bo)
            return 1;
        return 0;
        
        
    }
};