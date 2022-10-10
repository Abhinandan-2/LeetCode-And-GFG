class Solution {
public:
    
    bool isOk(vector<int> &a,vector<int> &b,int t){
        int n = a.size() , m = b.size(),in ;
        for(int i=0;i<n;i++){
            in = lower_bound(b.begin(),b.end(),a[i])-b.begin();
            // cout<<in<<" ";
            if(in!=m) if(abs(b[in]-a[i])<=t) continue;
            if(in==0||abs(b[in-1]-a[i])>t) return 0;
        }
        // cout<<5<<endl;
        return 1;
    }
    
    int findRadius(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n = a.size() , m1 = b.size();
        int l =0 , h = max(abs(b[0]-a[n-1]),abs(b[0]-a[0])),ans,m;
        
        while(l<=h)
        {
            m = l+(h-l)/2;
            // cout<<l<<" "<<m<<" "<<h<<endl;
            if(isOk(a,b,m))
            {
                ans = m;
                h = m-1;
            }
            else
                l= m+1;
        }
        
        return ans;
        
        
    }
};