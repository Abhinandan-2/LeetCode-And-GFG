class Solution {
public:
    int minimumOperations(vector<int>& a) {
        unordered_map<int,int> m;
        for(auto i:a)
            if(i!=0) m[i]++;
        return m.size();
    }
};