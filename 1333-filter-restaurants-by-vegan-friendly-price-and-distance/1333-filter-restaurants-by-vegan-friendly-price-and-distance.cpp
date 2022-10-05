class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& dhaba, int veg, int mxP, int mxD) {
        
        int n = dhaba.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            if((veg==0||dhaba[i][2]==1)&&dhaba[i][3]<=mxP&&dhaba[i][4]<=mxD){
                v.push_back({dhaba[i][1],dhaba[i][0]});
            }
        }
        sort(v.begin(),v.end(),greater<vector<int>>());
        vector<int> ans;
        for(int i=0;i<v.size();i++)
            ans.push_back(v[i][1]);
        return ans;
        
    }
};