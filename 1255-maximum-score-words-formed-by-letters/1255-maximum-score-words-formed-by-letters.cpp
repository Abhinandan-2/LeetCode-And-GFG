class Solution {
    
    void kanpsack(vector<string> &a,unordered_map<char,int> &occ,vector<int> &score,int &ans,int count,int i)
    {
        int n = a.size(),f=0;
        if(i==n)
        {
            ans = max(ans,count);
            return ;
        }
        unordered_map<char,int> help;
        for(auto j:a[i])
            help[j]++;
        for(auto i:help)
        {
            if(occ[i.first]<i.second)
            {
                f=1;
                break;
            }
        }
        
        kanpsack(a,occ,score,ans,count,i+1);
        
        if(f==1)
            return ;
        for(auto i:help)
        {
            occ[i.first]-=i.second;
            count += i.second*(score[i.first-97]);
        }
        
        kanpsack(a,occ,score,ans,count,i+1);
        
        for(auto i:help)
            occ[i.first]+=i.second;
        
        return ;  
    }
    
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        
        unordered_map<char,int> occ;
        for(auto i:l)
            occ[i]++;
        int ans =0 ,count =0; 
        kanpsack(w,occ,s,ans,count,0);
        return ans; 
    }
};