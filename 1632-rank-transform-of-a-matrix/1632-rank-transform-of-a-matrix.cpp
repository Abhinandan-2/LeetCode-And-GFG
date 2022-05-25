class Solution {
public:
    
    vector<vector<int>> help(vector<vector<int>> &a)
    {
        int n = a.size() , m = a[0].size();
        
        unordered_map<int,vector<pair<int,int>>> occ;
        unordered_map<int,vector<int>> row,col;
        unordered_map<int,int> rowh,colh;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                occ[a[i][j]].push_back({i,j});
        
        vector<vector<int>> ans;
        vector<int> help,v;
        queue<int> qu;
        int psz,pt;
        for(auto i:occ)
        {
            vector<pair<int,int>> &p = i.second;
            psz = p.size();
            row.clear();
            col.clear();
            for(int j=0;j<psz;j++)
            {
                row[p[j].first].push_back(j);
                col[p[j].second].push_back(j);
            }
            v.clear();
            v.assign(psz,-1);
            for(int j=0;j<psz;j++)
            {
                if(v[j]==-1)
                {
                    rowh.clear();
                    colh.clear();
                    help.clear();
                    help.push_back(i.first);
                    qu.push(j);
                    v[j] = 1;
                    while(!qu.empty())
                    {
                        pt = qu.front();
                        qu.pop();
                        help.push_back(p[pt].first);
                        help.push_back(p[pt].second);
                        if(!rowh.count(p[pt].first)){
                        vector<int> &hrow = row[p[pt].first];
                        for(int ij=0;ij<hrow.size();ij++)
                        {
                            if(v[hrow[ij]]==-1)
                            {
                                qu.push(hrow[ij]);
                                v[hrow[ij]] = 1;
                            }
                        }
                            rowh[p[pt].first]=1;
                        }
                        
                        if(!colh.count(p[pt].second)){
                        vector<int> &hcol = col[p[pt].second];
                        for(int ij=0;ij<hcol.size();ij++)
                        {
                            if(v[hcol[ij]]==-1)
                            {
                                qu.push(hcol[ij]);
                                v[hcol[ij]] = 1;
                            }
                        }
                        colh[p[pt].second]=1;
                        }
                        
                        
                        
                    }
                    ans.push_back(help);
                }
            }
        }
        
        return ans;
        
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> mainq;
        vector<vector<int>> helpVec = help(a);
        
        for(auto i:helpVec)
            mainq.push(i);
        
        
        vector<vector<int>> ans(n,vector<int> (m,0));
        
        vector<int> col(m,0),row(n,0);
        int rank , val;
        while(!mainq.empty())
        {
            const vector<int> &p = mainq.top();
            val = p[0];
            rank = INT_MIN;
            for(int i=1;i<p.size();i++)
            {
                if(i%2!=0)
                    rank = max(rank,row[p[i]]);
                else
                    rank = max(rank,col[p[i]]);
            }
            rank++;
            for(int i=1;i<p.size();i+=2)
            {
                ans[p[i]][p[i+1]] = rank;
                row[p[i]] = rank;
                col[p[i+1]]=rank;
            }
            mainq.pop();
        }
        
        
        return ans;
        
    }
};