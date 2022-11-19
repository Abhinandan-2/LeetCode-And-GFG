class Solution {
public:
    
    pair<int,int> findNext(vector<vector<int>> &a,pair<int,int> &p,int f){
        
        vector<double> slope;
        pair<int,int> ans;
        double help;
        for(int i=0;i<a.size();i++){
            if(a[i][0]==p.first){
                if(f==2||f==4) slope.push_back(-1000.0);
                else slope.push_back(1000.0);
            }
            else{
                help = (double)(a[i][1]-p.second)/(double)(a[i][0]-p.first);
                slope.push_back(help);
            }
        }
        
        help = 1001.0;
        
        for(int i=0;i<slope.size();i++){
            if(slope[i]<=help){
                if(slope[i]==help){
                    if(f==1){
                        if(a[i][0]>ans.first){
                            ans.first = a[i][0];
                            ans.second = a[i][1];
                        }
                    }
                    else if(f==2){
                        if(a[i][1]>ans.second){
                            ans.first = a[i][0];
                            ans.second = a[i][1];
                        }
                    }
                    else if(f==3){
                        if(a[i][0]<ans.first){
                            ans.first = a[i][0];
                            ans.second = a[i][1];
                        }
                    }
                    else if(f==4){
                        if(a[i][1]<ans.second){
                            ans.first = a[i][0];
                            ans.second = a[i][1];
                        }
                    }
                }
                else{
                    help = slope[i];
                    ans.first = a[i][0];
                    ans.second = a[i][1];
                }
            }
        }
        
        return ans;
        
    }
    
    pair<int,int> mainAlgo(pair<int,int> &point,set<vector<int>> &ans,int f,vector<vector<int>> a){
        // cout<<point.first<<" "<<point.second<<endl;
        vector<vector<int>> allWorthy;
        while(1){
            for(int i=0;i<a.size();i++){
                if(((f==1&&a[i][0]<=point.first)||(f==2&&a[i][1]<=point.second)||(f==3&&a[i][0]>=point.first)||(f==4&&a[i][1]>=point.second))&&(a[i][0]!=point.first||a[i][1]!=point.second)){
                        allWorthy.push_back({a[i][0],a[i][1]});
                }
            }
            if(allWorthy.size()==0) break;
            // for(auto i:allWorthy) cout<<i[0]<<" "<<i[1]<<endl;
            // cout<<endl;
            point = findNext(allWorthy,point,f);
            // cout<<point.first<<" "<<point.second<<endl;
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
        for(int i=0;i<n;i++){
            if(a[i][1]>=topRight.second){
                if(a[i][0]>=topRight.first){
                    topRight.second = a[i][1];
                    topRight.first = a[i][0];
                }
           }
        }
        // cout<<topRight.first<<" "<<topRight.second<<endl;
        // ans.push_back({topRight.first,topRight.second});
        leftTop = mainAlgo(topRight,res,1,a);
        // cout<<leftTop.first<<" "<<leftTop.second<<endl;
        // ans.push_back({leftTop.first,leftTop.second});
        downLeft = mainAlgo(leftTop,res,2,a);
        // ans.push_back({downLeft.first,downLeft.second});
        rightDown = mainAlgo(downLeft,res,3,a);
        topRight = mainAlgo(rightDown,res,4,a);
        
        for(auto i:res) ans.push_back(i);
        
        return ans;
        
//         leftTop = topRight;
        
//         while(1){
//             ans.push_back({leftTop.first,leftTop.second});
//             temp.clear();
//             for(int i=0;i<n;i++){
//                 if(a[i][1]<=leftTop.second)
//                     temp.push_back({a[i][0],a[i][1]});
//             }
//             if(temp.size()==0) break;
//             leftTop = findNext(temp,leftTop);
//         }
    
        
        
    }
};