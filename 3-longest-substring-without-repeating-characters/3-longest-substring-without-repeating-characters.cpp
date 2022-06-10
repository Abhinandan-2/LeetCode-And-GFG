class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        
        int n = a.size() , j =0 , i= 0 ,ans=0;
        unordered_map<char,int> m;
        while(i<n)
        {
            m[a[i]]++;
            while(m[a[i]]>1)
            {
                m[a[j]]--;
                j++;
            }
            
            ans = max(ans,i-j+1);
            i++;

        }
        
        return ans;
        
        
    }
};