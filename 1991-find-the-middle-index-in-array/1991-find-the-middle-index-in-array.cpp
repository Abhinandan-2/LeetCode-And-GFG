class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        
        int n = a.size(),l=0,r=accumulate(a.begin(),a.end(),0);
        for(int i=0;i<n;i++)
        {
            r -= a[i];
            if(l==r)
                return i;
            l+=a[i];
        }
        return -1;
    }
};