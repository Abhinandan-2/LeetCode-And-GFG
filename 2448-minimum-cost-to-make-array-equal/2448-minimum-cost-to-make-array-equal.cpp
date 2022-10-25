class Solution {
public:
    long long calCost(vector<int> &a,vector<int> &val,int m){
        long long ans =0 ;
        for(int i=0;i<a.size();i++) ans += abs(a[i]-m)*(long long)val[i];
        return ans;    
    }
    long long minCost(vector<int>& a, vector<int>& val) {
        int l = *min_element(a.begin(),a.end()),h = *max_element(a.begin(),a.end()),m, n = a.size();
        long long ans,low,high ;
        while(l<h){
            m = l+(h-l)/2;
            if(m==l){
                low = calCost(a,val,l);
                high = calCost(a,val,h);
                if(low<=high) h= l;
                else l = h;
            }
            else{
                low = calCost(a,val,m-1);
                high = calCost(a,val,m);
                if(low<=high) h = m;
                else l = m;
            }
        }
        ans = calCost(a,val,l);
        return ans;
    }
};