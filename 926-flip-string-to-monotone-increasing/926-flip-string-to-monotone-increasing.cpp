class Solution {
public:
    int minFlipsMonoIncr(string a) {
        
        int n = a.size();
        
        vector<int> zero(n,0) , one(n,0);
        if(a[0]=='1')
            one[0] = 1;
        for(int i=1;i<n;i++)
        {
            one[i] = one[i-1];
            if(a[i]=='1')
                one[i]++;
        }
        if(a[n-1]=='0')
            zero[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            zero[i] = zero[i+1];
            if(a[i]=='0')
                zero[i]++;
        }
        // for(auto i:one)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto i:zero)
        //     cout<<i<<" ";
        // cout<<endl;
        
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++)
            ans = min(ans,one[i]+zero[i+1]);
        ans = min(ans,zero[0]);
        ans = min(ans,one[n-1]);
        return ans;
        
        
    }
};