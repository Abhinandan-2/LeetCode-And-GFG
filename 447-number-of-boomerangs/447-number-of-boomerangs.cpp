class Solution {
    
    int call(vector<int> &a,vector<int> &b)
    {
        int h,k;
        h = (a[0]-b[0])*(a[0]-b[0]);
        k = (a[1]-b[1])*(a[1]-b[1]);
        return h+k;
    }
    
public:
    int numberOfBoomerangs(vector<vector<int>>& a) {
        
        int ans =0,n = a.size(),h,dis;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j){
                dis = call(a[i],a[j]);
                m[dis]++;
                }
            }
            
            for(auto i:m)
            {
                if(i.second>=2)
                {
                    h = (i.second*(i.second-1));
                    ans += h;
                }
            }
            m.clear();
            
        }
        
        return ans;
        
        
    }
};