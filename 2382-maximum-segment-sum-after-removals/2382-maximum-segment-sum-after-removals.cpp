#define ll long long

class Solution {
    
    ll find_sum(int start,int end,vector<ll> &sum)
    {
        if(start==0)
            return sum[end];
        return sum[end]-sum[start-1];
    }
    
public:
    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& t) {
        
        int n = a.size();
        ll br,val1,val2,val,res;
        
        set<pair<int,int>> seg ;
        multiset<ll> value;
        pair<int,int> p;
        
        vector<ll> prefixSum(n),ans;
        prefixSum[0] = a[0];
        for(int i=1;i<n;i++)
            prefixSum[i] = a[i]+prefixSum[i-1];
       
        seg.insert({0,n-1});
        value.insert(prefixSum[n-1]);
        
        for(int i=0;i<n-1;i++)
        {
            val1=-1,val2=-1;
            br = t[i];
            auto it = seg.lower_bound({br,br});
            if(it==seg.end()) it--;
            if(it->first>br) it--;
            p = *it;
            val = find_sum(p.first,p.second,prefixSum);
            seg.erase(it);
            auto ik = value.lower_bound(val);
            value.erase(ik);
            if(p.first==br){
                seg.insert({br+1,p.second});
                val1 = find_sum(br+1,p.second,prefixSum);
            }
            else if(p.second==br){
                seg.insert({p.first,br-1});
                val2 = find_sum(p.first,br-1,prefixSum);
            }
            else{
                seg.insert({p.first,br-1});
                seg.insert({br+1,p.second});
                val1 = find_sum(p.first,br-1,prefixSum);
                val2 = find_sum(br+1,p.second,prefixSum);
            }
            if(val1!=-1) value.insert(val1);
            if(val2!=-1) value.insert(val2);
            auto last = value.end();
            last--;
            res = *last;
            ans.push_back(res);
        }
        
        ans.push_back(0);
        return ans;
        
    }
};