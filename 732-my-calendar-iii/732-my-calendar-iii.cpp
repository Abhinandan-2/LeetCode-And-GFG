class MyCalendarThree {
    
    vector<pair<int,int>> ans;
    
public:
    MyCalendarThree() {
        return ;
    }
    
    int book(int start, int end) {
        
        ans.push_back({start,1});
        ans.push_back({end,0});
        sort(ans.begin(),ans.end());
        int count=0,res=0;
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].second==1)
                count++;
            else
                count--;
            res = max(res,count);
        }
        return res;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */