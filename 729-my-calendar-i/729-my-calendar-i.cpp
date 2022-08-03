class MyCalendar {
    
    vector<vector<int>> a;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        
        int n = a.size(),f=0;
        e--;
        //cout<<s<<" "<<e<<" ";
        for(int i=0;i<n;i++)
        {
            // if(s==35&&e==47)
            //     cout<<a[i][0]<<" "<<a[i][1]<<endl;
            if((a[i][0]>=s&&a[i][0]<=e)||(a[i][1]>=s&&a[i][1]<=e)||(s>=a[i][0]&&e<=a[i][1]))
            {
                 f=1;
                break;
            }
        }
        if(f==1)
        {
            //cout<<0<<endl;
            return 0;
        }
        a.push_back({s,e});
        //cout<<1<<endl;
        return 1;
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */