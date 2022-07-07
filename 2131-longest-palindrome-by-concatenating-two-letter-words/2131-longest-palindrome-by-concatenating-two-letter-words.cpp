class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        
        int n = a.size();
        unordered_map<string,int> m;
        
        for(int i=0;i<n;i++)
            m[a[i]]++;
        // for(auto i:m)
        //     cout<<i.first<<" "<<i.second<<endl;
        int ans =0 , f =0;
        string k;
        for(int i=0;i<n;i++)
        {
            if(m.count(a[i]))
            {
                // cout<<a[i]<<" ";
                if(a[i][0]==a[i][1])
                {
                    ans += (m[a[i]]/2)*4;
                    if(m[a[i]]%2!=0&&f==0)
                    {
                        ans+=2;
                        f=1;
                    }
                    
                }
                else
                {
                    k = a[i];
                    reverse(k.begin(),k.end());
                    if(m.count(k))
                    {
                        ans += min(m[a[i]],m[k])*4;
                        m.erase(k);
                    }
                    
                }
                m.erase(a[i]);
            }
            // cout<<ans<<endl;
        }
        
        return ans;
        
        
    }
};