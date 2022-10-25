class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
        string first , second;
        for(auto i:a) first += i;
        for(auto i:b) second += i;
        return first==second;
    }
};