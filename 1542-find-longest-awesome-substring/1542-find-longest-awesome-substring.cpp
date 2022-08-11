class Solution {
public:
    int longestAwesome(string a) {
        
        // Xor -> xor of same value become 0....
        
        int n = a.size(),bit =0, temp =0, mask, ans =0;
        unordered_map<int,int> m;
        m[bit] = -1;
        for(int i=0;i<n;i++)
        {
            mask = 1<<(a[i]-48);
            bit ^= mask;
            if(m.count(bit))
                ans = max(ans,i-m[bit]);
            // cout<<bit<<" ";
            for(int j=0;j<10;j++)
            {
                mask = 1<<j;
                temp = bit^mask;
                if(m.count(temp))
                    ans= max(ans,i-m[temp]);
                // cout<<temp<<" ";
            }
            if(!m.count(bit))
                m[bit] = i;
            // cout<<ans<<endl;
        }
        return ans;
        
    }
};