class Solution {
public:
    pair<int,int> findNext(vector<vector<int>> &a,pair<int,int> &p,int f){
        vector<double> slope;
        pair<int,int> ans;
        double help;
        for(int i=0;i<a.size();i++) a[i][0]==p.first ? (f==2||f==4) ? slope.push_back(-1000.0) : slope.push_back(1000.0) : slope.push_back((double)(a[i][1]-p.second)/(double)(a[i][0]-p.first));
        help = 1001.0;
        for(int i=0;i<slope.size();i++){
            if(slope[i]<=help){
                if(slope[i]==help){
                    if((f==1&&a[i][0]>ans.first)||(f==2&&a[i][1]>ans.second)||(f==3&&a[i][0]<ans.first)||(f==4&&a[i][1]<ans.second)){ans.first = a[i][0];ans.second = a[i][1];}}
                else{help = slope[i];ans.first = a[i][0];ans.second = a[i][1];}
            }
        }
        return ans;
    }
    pair<int,int> mainAlgo(pair<int,int> &point,set<vector<int>> &ans,int f,vector<vector<int>> a){
        vector<vector<int>> allWorthy;
        while(1){
            for(int i=0;i<a.size();i++) if(((f==1&&a[i][0]<=point.first)||(f==2&&a[i][1]<=point.second)||(f==3&&a[i][0]>=point.first)||(f==4&&a[i][1]>=point.second))&&(a[i][0]!=point.first||a[i][1]!=point.second)) allWorthy.push_back({a[i][0],a[i][1]});
            if(allWorthy.size()==0) break;
            point = findNext(allWorthy,point,f);
            ans.insert({point.first,point.second});
            a = allWorthy;
            allWorthy.clear();
        }
        return point;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& a) {
        int n = a.size()  ;
        if(n==1) return a;
        pair<int,int> topRight = {INT_MIN,INT_MIN},leftTop,downLeft,rightDown;
        vector<vector<int>> ans;
        set<vector<int>> res;
        for(int i=0;i<n;i++) if(a[i][1]>=topRight.second) if(a[i][0]>=topRight.first){topRight.second = a[i][1];topRight.first = a[i][0];}
        leftTop = mainAlgo(topRight,res,1,a);
        downLeft = mainAlgo(leftTop,res,2,a);
        rightDown = mainAlgo(downLeft,res,3,a);
        topRight = mainAlgo(rightDown,res,4,a);
        for(auto i:res) ans.push_back(i);
        return ans;
    }
};