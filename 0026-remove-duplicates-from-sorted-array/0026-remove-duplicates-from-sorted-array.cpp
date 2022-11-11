class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        
        int n = a.size(),j=0;
        if(n==0)
            return 0;
        for(int i=1;i<n;i++)
        {
            if(a[j]!=a[i])
            {
                swap(a[j+1],a[i]);
                j++;
            }
        }
        return j+1;
        
    }
};