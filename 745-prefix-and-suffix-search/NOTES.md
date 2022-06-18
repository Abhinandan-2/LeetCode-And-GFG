**Two Approch**
​
**1. Trie Solution**
​
```
class node {
public :
char val;
vector<int> v;
unordered_map<char,node*> m;
node(char p){
val = p;
}
};
​
​
class trie
{
node *root ;
public :
trie(){
root = new node('/0');