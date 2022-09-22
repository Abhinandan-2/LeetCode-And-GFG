class Solution {
public:
    
    void revers(string &a,int s,int e)
    {
        for(int i=s,j=e-1;i<j;i++,j--)
            swap(a[i],a[j]);
        return ;
    }
    
    string reverseWords(string a) {
        
        int n = a.size(),s=0,e=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==' ')
            {
                e = i;
                revers(a,s,e);
                s = i+1;
            }
            
        }
        revers(a,s,n);
        return a;
        
    }
};