class Solution {
public:
    int dayOfYear(string &a) {
        
        vector<int> mo{31,28,31,30,31,30,31,31,30,31,30,31};
        
        for(int i=1;i<12;i++)
            mo[i]+=mo[i-1];
        
        int d = stoi(a.substr(8,2));
        int m = stoi(a.substr(5,2));
        int y = stoi(a.substr(0,4));
        int ans =0;
        ans += d;
        if(m!=1)
        ans += mo[m-2];
        if(((y%4==0&&y%100!=0)||y%400==0)&&m>2)
        ans++;
        return ans;
        
    }
};