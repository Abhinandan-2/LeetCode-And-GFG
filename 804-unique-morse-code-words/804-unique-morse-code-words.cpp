class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& a) {
        
        string v[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int n  = a.size() , h;
        string k;
        
        unordered_map<char,string> m;
        for(int i=0;i<26;i++)
        {
            m[i+97] = v[i];
        }
        unordered_set<string> s;
        for(int i=0;i<n;i++)
        {
            h = a[i].size();
            k = "";
            for(int j=0;j<h;j++)
            {
                k += m[a[i][j]];
            }
            s.insert(k);
        }
        
        return s.size();
        
        
    }
};