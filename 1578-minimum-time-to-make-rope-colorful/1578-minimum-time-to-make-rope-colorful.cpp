class Solution {
public:
    int minCost(string a, vector<int>& b) {
        
        int i=0,j=1, n = a.size() , ans =0 ;
        while(j<n)
        {
            if(a[i]==a[j])
            {
                if(b[i]<b[j])
                {
                    ans += b[i];
                    i =j;
                }
                else ans += b[j];
            }
            else i = j;
            j++;
        }
        return ans;
        
    }
};