class Solution {
public:
    static bool com(vector<int> &a,vector<int> &b){ return a[0]==b[0] ? a[2]>b[2] : a[0]<b[0];}
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        int n = a.size(),mx=0,mx1,x;
        sort(a.begin(),a.end(),com);
        vector<vector<int>> ans;
        set<pair<int,int>> dis, high;
        pair<int,int> p;
        for(int i=0;i<n;i++){
            if(dis.empty()) x = INT_MAX;
            else x = (*dis.begin()).first;
            if(a[i][0]<=x){
                if(a[i][2]>mx){
                    mx = a[i][2];
                    ans.push_back({a[i][0],mx});
                }
                dis.insert({a[i][1],a[i][2]});
                high.insert({a[i][2],a[i][1]});
            }
            else{
                p = *dis.begin();
                dis.erase(dis.begin());
                high.erase({p.second,p.first});
                if(dis.empty()||(*dis.begin()).first!=p.first&&p.second==mx)
                {
                    if(dis.empty())   {
                        ans.push_back({p.first,0});
                        mx =0; 
                    }
                    else{
                        mx1 = (*high.rbegin()).first;
                        if(mx!=mx1){
                            mx = mx1;
                            ans.push_back({p.first,mx});
                        }
                    }
                }
                i--;
            }
        }
        while(!dis.empty()){
            p = *dis.begin();
            dis.erase(dis.begin());
            high.erase({p.second,p.first});
            if(dis.empty()||(*dis.begin()).first!=p.first){
                if(p.second==mx){
                    if(dis.empty())   {
                        ans.push_back({p.first,0});
                        mx =0; 
                    }
                    else{
                        mx1 = (*high.rbegin()).first;
                        if(mx!=mx1){
                            mx = mx1;
                            ans.push_back({p.first,mx});
                        }
                    }
                }
            }
        }
        return ans;
    }
};