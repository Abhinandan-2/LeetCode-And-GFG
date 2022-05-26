class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n =a.size();
        unordered_map<int,int> m;
        int ans =0 , f =0;
        for(int i=0;i<n;i++)
        {
            f=0;
            m[a[i]]++;
            for(int j=0;j<=i;j++)
            {
                if(!m.count(j))
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ans++;
        }
        return ans;
        
        
    }
};