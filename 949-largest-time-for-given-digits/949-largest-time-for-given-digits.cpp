class Solution {
public:
    
    bool isIn(int num,vector<int> &a,bool is)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==num)
            {
                if(is)
                {
                    a.erase(a.begin()+i);
                    return 1;
                }
                else
                    return 1;
            }
        }
        return 0;
    }
    
    string largestTimeFromDigits(vector<int>& a) {
        
        string ans ;
        vector<int> t;
        int min , min1,min2,mx;
        if(isIn(2,a,1))
        {
            t.push_back(2);
            if(isIn(3,a,1)){
                ans = "23:";
                t.push_back(3);
        }
            else if(isIn(2,a,1)){
                ans = "22:";
                t.push_back(2);
        }
            else if(isIn(1,a,1)){
                ans = "21:";
                t.push_back(1);
        }
            else if(isIn(0,a,1)){
                ans = "20:";
                t.push_back(0);
        }
            else
                return "";
            
            min1 = a[0]+a[1]*10;
            min2 = a[1]+a[0]*10;
            if(min1<60&&min2<60)
            {
                min = max(min1,min2);
                ans += to_string(min);
                if(min<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
            if(min1<60)
            {
                ans += to_string(min1);
                if(min1<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
            if(min2<60)
            {
                ans += to_string(min2);
                if(min2<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
        }
        
        for(int i=0;i<t.size();i++)
            a.push_back(t[i]);
        ans.clear();
        if(isIn(1,a,0)||isIn(0,a,0))
        {
            // cout<<"yes";
            if(isIn(1,a,1))
            ans = "1";
            else if(isIn(0,a,1))
            ans = "0";
            mx = *max_element(a.begin(),a.end());
            isIn(mx,a,1);
            // for(auto i:a)
            //     cout<<i<<" ";
            ans += to_string(mx);
            ans += ":";
            // cout<<ans;
            min1 = a[0]+a[1]*10;
            min2 = a[1]+a[0]*10;
            if(min1<60&&min2<60)
            {
                min = max(min1,min2);
                ans += to_string(min);
                if(min<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
            if(min1<60)
            {
                ans += to_string(min1);
                if(min1<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
            if(min2<60)
            {
                ans += to_string(min2);
                if(min2<10)
                    ans.insert(ans.begin()+3,'0');
                return ans;
            }
        }
        return "";
    }
};