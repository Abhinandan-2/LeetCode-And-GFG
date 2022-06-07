class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        
        int h = a.size();
        
        for(int i=n-1;i>=0;i--)
            swap(a[i],a[i+m]);
        
        int i=m,j=0,k=0;
        
        while(i<h&&j<m)
        {
            if(a[i]<=b[j])
                a[k++] = a[i++];
            else
                a[k++] = b[j++];
        }
        
        while(i<h)
            a[k++] = a[i++];
        while(j<m)
            a[k++] = b[j++];
        return ;
        
    }
};