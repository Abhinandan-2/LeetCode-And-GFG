class node{
    public :
    char c;
    unordered_map<char,node*> m; // To store pointer to its next characters
    int cn =0 ;  // To store count how many times this character appears in every prefix of every string of a given vector
};

class trie{
    node *r;  // Root node
    public :
    trie(){
        r = new node;
        r->c = '\0';
        r->cn = 0;
    }
    void push(string a){
        node *p = r;
        for(int i=0;i<a.size();i++){
            if(p->m.count(a[i])){     // If its next character is present in trie, move to that character
                p = p->m[a[i]];
                p->cn++;              // Increase count, Because it is present in prefix of current string(a)
            }
            else{
                node *l = new node;  // If its next character is not present in trie, create new node
                l->c = a[i];
                l->cn = 1;           // Count = 1
                p->m[a[i]]= l;
                p = l;
            }
        }
        return ;
    }
    int score(string a){
        int ans =0 ;
        node *p = r;
        for(int i=0;i<a.size();i++){    // Add all count of character by traversing trie for current string(a)
            p= p->m[a[i]];
            ans += p->cn;           
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& a) {
        trie t;
        int n = a.size();
        for(int i=0;i<n;i++) t.push(a[i]);              // Push all string in trie
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]= t.score(a[i]);    //  Get the score of strings
        return ans;
    }
};