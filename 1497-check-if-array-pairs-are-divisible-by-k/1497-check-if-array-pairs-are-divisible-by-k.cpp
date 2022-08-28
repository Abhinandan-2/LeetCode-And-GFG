class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        
        int n = a.size();
        unordered_map<int,int> m;
        for(auto i:a)
        {
            i %= k;
            i += k;
            m[i%k]++;
        }
        
        for(int i=0;i<=k/2;i++)
        {
            if(i==0||i==k-i)
            {
                if(m[i]%2!=0)
                    return 0;
            }
            else
            {
                if(m[i]!=m[k-i])
                    return 0;
            }
        }
        return 1;
        
    }
};