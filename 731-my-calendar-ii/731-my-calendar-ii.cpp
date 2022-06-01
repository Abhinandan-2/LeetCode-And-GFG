class MyCalendarTwo {
    
    vector<pair<int,int>> booking;
    
public:
    MyCalendarTwo() {
        return ;
    }
    
    bool book(int start, int end) {
        
        vector<pair<int,int>> help = booking;
        help.push_back({start,1});
        help.push_back({end,0});
        sort(help.begin(),help.end());
        
        int count=0;
        for(int i=0;i<help.size();i++)
        {
            if(help[i].second==1)
                count++;
            else
                count--;
            if(count>=3)
                return false;
        }
        booking.push_back({start,1});
        booking.push_back({end,0});
        
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */