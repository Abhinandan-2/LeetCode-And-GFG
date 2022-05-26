class Solution {
public:
    int totalFruit(vector<int>& a) {
        
        int n = a.size();
        unordered_map<int,int> m;
        int ans =0;
        int j=0,i=0;
        while(i<n)
        {
            m[a[i]]++;
            while(m.size()>2)
            {
                m[a[j]]--;
                if(m[a[j]]==0)
                    m.erase(a[j]);
                j++;
            }
            ans = max(ans,(i-j+1));
            i++;
        }
        return ans;
        
    }
};