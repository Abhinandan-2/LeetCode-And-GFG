class DetectSquares {
    
    map<pair<int,int>,int> cord;
    
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        
        cord[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {
        int ans =0 ,dis;
        
        unordered_map<int,int> x,y;
        
        for(auto i:cord){
            if(i.first.second==point[1]){
                x[i.first.first] += i.second;
            }
        }
        for(auto i:cord){
            if(i.first.first==point[0]){
                y[i.first.second] += i.second;
            }
        }
        
        for(auto i:x){
            // cout<<i.first<<" "<<i.second<<" ";
            dis = abs(i.first-point[0]);
            // cout<<dis<<" ";
            if(dis!=0&&y[point[1]-dis]!=0&&cord[{i.first,point[1]-dis}]!=0){
                
                ans += (i.second*y[point[1]-dis]*cord[{i.first,point[1]-dis}]);
                // cout<<ans<<" ";
            }
            if(dis!=0&&y[point[1]+dis]!=0&&cord[{i.first,point[1]+dis}]!=0){
                ans += (i.second*y[point[1]+dis]*cord[{i.first,point[1]+dis}]);
            }
            // cout<<endl;
            
        }
        // cout<<endl;
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */