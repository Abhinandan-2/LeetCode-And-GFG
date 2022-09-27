class Solution {
public:
    string pushDominoes(string a) {
        
        int n = a.size(),h,j,f=-1;
        char l = 'L',r;
        for(int i=0;i<=n;i++)
        {
            if(i<n)
            r = a[i];
            else
            r ='R';
            if(r!='.')
            {
                if(l=='L'&&r=='L')
                    for(int j=f+1;j<i;j++)
                        a[j]='L';
                else if(l=='R'&&r=='R')
                    for(int j=f+1;j<i;j++)
                        a[j]='R';
                else if(l=='R'&&r=='L')
                {
                    h = i-f-1;
                    j = i;
                    while(!(h==0||h==1))
                    {
                        a[++f] = 'R';
                        a[--j] = 'L';
                        h-=2;
                    }
                    l = 'L';
                }
                else
                    l= 'R';
                f=i;
            }
        }
        return a;
        
        
        
    }
};