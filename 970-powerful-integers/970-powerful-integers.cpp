class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int t) {
        
        set<int> res;
        
        vector<int> a,b,ans;
        if(t==0||t==1)
            return ans;
        
        int  p= 0,h ;
        if(x==1)
            a.push_back(1);
        else{
        while(1)
        {
            h = pow(x,p);
            if(h>t)
                break;
            a.push_back(h);
            p++;
        }
        }
        
        p=0 ;
        if(y==1)
            b.push_back(1);
        else{
        while(1)
        {
            h = pow(y,p);
            if(h>t)
                break;
            b.push_back(h);
            p++;
        } 
        }
//         for(auto i:a)
//             cout<<i<<" ";
//         cout<<endl;
        
//         for(auto i:b)
//             cout<<i<<" ";
//         cout<<endl;
        
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                if(a[i]+b[j]>t)
                    break;
                res.insert(a[i]+b[j]);
            }
        }
        
        for(auto i:res)
            ans.push_back(i);
        
        return ans;
        
    }
};