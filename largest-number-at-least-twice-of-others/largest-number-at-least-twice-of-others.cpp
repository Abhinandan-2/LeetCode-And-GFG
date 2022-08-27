class Solution {
public:
    int dominantIndex(vector<int>& a) {
        
        int pos = max_element(a.begin(),a.end())-a.begin();
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(i!=pos)
            {
                if(a[i]*2>a[pos])
                    return -1;
            }
        }
        return pos;
        
    }
};