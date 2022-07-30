class Solution {
public:
    int reachNumber(int t) {
        
        if(t<0)
            t*=-1;
        int j =1 ,num =0;
        vector<int> ans;
        ans.push_back(num);
        while(num+j<=t)
        {
            ans.push_back(num+j);
            num += j;
            j++;
        }
        
        int h = ans.size()-1;
        if(ans[h]==t)
            return h;
        int d = t-ans[h];
        if(h%2!=0)
        {
            if(d%2!=0)
                return h+2;
            return h+1;
        }
        if(d%2!=0)
            return h+1;
        return h+3;
        
    }
};