class Solution {
    bool isAllvisited(vector<int> &v){
        for(auto i:v) if(i==-1) return 0;
        return 1;
    }
    void call(vector<int> &a,vector<int> &v,int &ans,int last){
        int n = a.size(),pow,sq;
        if(isAllvisited(v)){ans++;return ;}
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(v[i]==-1&&!m.count(a[i])){
                sq = sqrt(last+a[i]);
                if(last+a[i]==sq*sq){
                    v[i]=1;
                    call(a,v,ans,a[i]);
                    v[i]=-1;
                }
                m[a[i]]++;
            }
        }
        return ;
    }   
public:
    int numSquarefulPerms(vector<int>& a) {
        int n = a.size() ,ans=0;
        vector<int> v(n,-1);
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(!m.count(a[i])){
                v[i] = 1;
                call(a,v,ans,a[i]);
                v[i] = -1;
                m[a[i]]++;
            }
        }
        return ans;
    }
};