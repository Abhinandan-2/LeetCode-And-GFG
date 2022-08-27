class Solution {
public:
    int maximumGap(vector<int>& a) {
        
         vector<int> b;
    int n =a.size();
    if(n<2)
        return 0;
    map<int,int> mp;
    int m =0;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(auto i:mp)
    {
        for(int j=0;j<i.second;j++)
        {
            b.push_back(i.first);
        }
    }
    for(int i=1;i<n;i++)
    {
        if(b[i]-b[i-1]>m)
        {
            m= b[i]-b[i-1];
        }
    }

    return m;
        
    }
};