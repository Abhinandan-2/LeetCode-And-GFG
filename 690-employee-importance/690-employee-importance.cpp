/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> a, int s) {
        
        int n = a.size();
        unordered_map<int,Employee*> m;
        
        for(int i=0;i<n;i++)
            m[a[i]->id] = a[i];
        
        int ans =0;
        
        queue<int> q;
        int p,h;
        
        q.push(s);
        
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            ans += m[p]->importance;
            for(int i=0;i<m[p]->subordinates.size();i++)
                q.push(m[p]->subordinates[i]);
        }
        return ans;
        
    }
};