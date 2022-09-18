for(int i=0;i<a.size();i++){    // Add all count of character by traversing trie for current string(a)
p= p->m[a[i]];
ans += p->cn;
}
return ans;
}
};
​
class Solution {
public:
vector<int> sumPrefixScores(vector<string>& a) {
trie t;
int n = a.size();
for(int i=0;i<n;i++) t.push(a[i]);              // Push all string in trie
vector<int> ans(n);
for(int i=0;i<n;i++) ans[i]= t.score(a[i]);    //  Get the score of strings
return ans;
}
};
```
​
**Time Complexity - O(NM)**  => O(C)
N is the length of the given array
M is the length of the string (This may not be the same for all strings)
C is the number of characters present in the given vector
l->cn = 1;           // Count = 1