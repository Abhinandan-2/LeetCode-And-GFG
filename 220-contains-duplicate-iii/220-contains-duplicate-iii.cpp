#define ll long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) { 
        if(k==0) return 0;
        int n = a.size();
        ll dif;
        multiset<int>::iterator it;
        multiset<int> s;
        for(int i=0;i<min(k+1,n);i++) s.insert(a[i]);
        for(auto it=s.begin();it!=s.end();it++){
            auto ij = it;ij++;
            if(ij!=s.end()){
                dif = abs((ll)(*it)-(ll)(*ij));
                if(dif<=(ll)t) return 1;
            }
        }
        for(int i=k+1;i<n;i++){
            s.erase(s.find(a[i-k-1]));
            auto ij = s.lower_bound(a[i]);
            if(ij==s.end()){
                ij--;
                dif = abs((ll)(*ij)-(ll)(a[i]));
                if(dif<=(ll)t) return 1;
                s.insert(a[i]);
                continue;
            }
            dif = abs((ll)(*ij)-(ll)(a[i]));
            if(dif<=(ll)t) return 1;
            if(ij!=s.begin()){
                ij--;
                dif = abs((ll)(*ij)-(ll)(a[i]));
                if(dif<=(ll)t) return 1;
            }
            s.insert(a[i]);  
        }
        return 0;
    }
};