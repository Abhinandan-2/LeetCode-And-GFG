class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        
        int n = a.size();
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i] = {a[i]+b[i],i};
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>> ());
        int al =0 , bob =0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                al += a[v[i].second];
            else
                bob+= b[v[i].second];
        }
        
        if(al>bob)
            return 1;
        if(bob>al)
            return -1;
        return 0;
        
    }
};