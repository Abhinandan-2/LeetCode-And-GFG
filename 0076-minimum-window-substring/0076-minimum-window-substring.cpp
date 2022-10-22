class Solution {
    bool isGreater(unordered_map<char,int> &runingMap,unordered_map<char,int> &fixMap){
        for(auto i:fixMap) if(runingMap[i.first]<i.second) return 0;
        return 1;
    }
public:
    string minWindow(string a, string b) {
        int n = a.size() , m = b.size() ,mx= INT_MAX, pos = -1,i=0,j=0;
        unordered_map<char,int> runingMap,fixMap;
        for(auto i:b) fixMap[i]++;
        while(i<n){
            runingMap[a[i]]++;
            if(isGreater(runingMap,fixMap)){
                while(isGreater(runingMap,fixMap)){
                    runingMap[a[j]]--;
                    j++;
                }
                if(mx>i-j+2){
                    mx = i-j+2;
                    pos = i;
                }
            }
            i++;
        }
        if(pos==-1) return "";
        return a.substr(pos-mx+1,mx);
    }
};