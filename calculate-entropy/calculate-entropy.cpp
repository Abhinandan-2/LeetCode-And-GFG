class Solution {
public:
    double calculateEntropy(vector<int>& a) {
        
        double ans =0 , h =0,k=0 ;
        unordered_map<int,int> m;
        int n = a.size();
        
        for(auto i:a)
            m[i]++;
        
        for(auto i:m)
        {
            h = (double)i.second/(double)n;
            k = log2(h)/log2(2);
            // cout<<k<<" "<<h<<endl;
            k *= h;
            ans -= k;
        }
        
        return ans;
    }
};