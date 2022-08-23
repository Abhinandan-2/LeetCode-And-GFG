class Solution {
public:
    int countSpecialNumbers(int n) {
        
        if(n<10)
            return n;
        
        vector<int> v;
        
        while(n)
        {
            v.push_back(n%10);
            n/=10;
        }
        
        reverse(v.begin(),v.end());
        
        int ans =0,j=1,t=9, k = v.size(),c=0;
        
        for(int i=0;i<k-1;i++)
        {
            if(i==0)
            j *= 9;
            else
            {
                j *= t;
                t--;
            }
            ans += j;
            // cout<<ans<<" ";
        }
        
        unordered_map<int,int> m;
        
        j = 1;
        t = 9;
        for(int i=1;i<k;i++)
        {
            j *= t;
            t--;
        }
        j *= v[0]-1;
        ans += j;
        // cout<<ans<<" ";
        m[v[0]]++;
        for(int i=1;i<k;i++)
        {
            
            c=0 ;
            for(auto p:m)
                if(p.first<v[i])
                    c++;
            j = 1;
            t = 10-i-1;
            for(int p=i+1;p<k;p++)
            {
                j *=t;
                t--;
            }
            j *= v[i]-c;
            ans += j;
            if(m.count(v[i]))
                return ans;
            m[v[i]]++;
            // cout<<ans<<" ";
        }
        ans++;
       
        return ans;
        
        
    }
};
