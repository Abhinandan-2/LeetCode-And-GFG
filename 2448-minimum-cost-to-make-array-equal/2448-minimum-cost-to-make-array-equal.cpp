class Solution {
public:
    
    long long calCost(vector<int> &a,vector<int> &val,int m,int f=0){
        long long ans =0 ;
        int n = a.size();
        for(int i=0;i<n;i++){
         long long d =   abs(a[i]-m); 
         ans += d*(long long)val[i];
            // if(f)
            // cout<<m<<" "<<d<<" "<<val[i]<<" "<<ans<<endl;
        }
        return ans;
            
    }
    
    long long minCost(vector<int>& a, vector<int>& val) {
        
        int n = a.size();
        int l = *min_element(a.begin(),a.end());
        int h = *max_element(a.begin(),a.end());
        int m ;
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
        // cout<<l<<endl;
        ans = calCost(a,val,l,1);
        return ans;
        
    }
};