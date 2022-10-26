class FindSumPairs {
    unordered_map<int,int> m;
    vector<int> first,second;
public:
    FindSumPairs(vector<int>& a, vector<int>& b) {
        first = a;
        second = b;
        for(auto i:b) m[i]++;
    }
    
    void add(int index, int val) {
        m[second[index]]--;
        if(m[second[index]]==0) m.erase(second[index]);
        second[index] += val;
        m[second[index]]++;
        return ;
        
    }
    
    int count(int tot) {
        int ans =0 ,n = first.size();
        for(int i=0;i<n;i++) if(m.count(tot-first[i])) ans += m[tot-first[i]];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */