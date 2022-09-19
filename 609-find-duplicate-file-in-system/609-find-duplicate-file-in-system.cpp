class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& a) {
        
        int n = a.size(),len,f;
        vector<vector<string>> ans;
        // vector<string> res;
        string help,path,content,file;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++)
        {
            stringstream c(a[i]);
            f=0;
            while(getline(c,help,' '))
            {
                if(f==0)
                {
                    path = help;
                    f++;
                }
                else
                {
                    len = help.size();
                    len-=2;
                    while(help[len]!='(')
                        content.push_back(help[len--]);
                    len--;
                    while(len>=0)
                        file.push_back(help[len--]);
                    reverse(file.begin(),file.end());
                    mp[content].push_back(path+"/"+file);
                    content.clear();
                    file.clear();
                }
            }
        }
        
        for(auto i:mp)
        {
            if(i.second.size()>=2)
            ans.push_back(i.second);
        }
        return ans;
    }
};