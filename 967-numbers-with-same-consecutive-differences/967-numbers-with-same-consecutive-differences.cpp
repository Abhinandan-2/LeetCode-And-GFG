class Solution {
public:
    
    int VecToInt(vector<int> &b)
    {
        int n = b.size()  , ans =0;
        for(auto i:b)
        {
            ans *= 10;
            ans += i;
        }
        return ans;
    }
    
    void call(int i,vector<int> &ans,vector<int> &b,int n,int k)
    {
        //cout<<i<<endl;
        int h ;
        if(b.size()==n)
        {
            h = VecToInt(b);
            ans.push_back(h);
            return ;
        }
        
        if(i+k<10)
        {
            b.push_back(i+k);
            call(i+k,ans,b,n,k);
            b.pop_back();
        }
        if(k!=0&&i-k>=0)
        {
            b.push_back(i-k);
            call(i-k,ans,b,n,k);
            b.pop_back();
        }
        return ;
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans , b ; 
        for(int i=1;i<=9;i++)
        {
            b.push_back(i);
            call(i,ans,b,n,k);
            b.pop_back();
        }
        return ans;   
    }
};