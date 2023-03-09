//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    void call(int n,unordered_map<char,int> &m,unordered_map<char,int> &v,Node *a,Node *b,vector<Node*> &ans){
        if(b==NULL) return ;
        if(a!=b){
            if(v==m){
                ans.push_back(a);
                v.clear();
                Node *h = b->next;
                b->next = NULL;
                call(n,m,v,h,h,ans);
            }
            else{
                v[a->data]--;
                if(b->next) v[b->next->data]++;
                if(v[a->data]==0) v.erase(a->data);
                call(n,m,v,a->next,b->next,ans);
            }
            return ;
        }
        int k = n;
        k--;
        while(b&&k){
            v[b->data]++;
            b=b->next;
            k--;
        }
        if(k!=0||b==NULL) return ;
        v[b->data]++;
        if(v==m){
            ans.push_back(a);
            v.clear();
            Node *h = b->next;
            b->next = NULL;
            call(n,m,v,h,h,ans);
        }
        else{
            v[a->data]--;
            if(b->next) v[b->next->data]++;
            if(v[a->data]==0) v.erase(a->data);
            call(n,m,v,a->next,b->next,ans);
        }
        return ;
    }
  
    vector<Node*> findAnagrams(struct Node* a, string s) {
        int n = s.size();
        unordered_map<char,int> m , v;
        vector<Node*> ans;
        for(auto &i:s) m[i]++;
        call(n,m,v,a,a,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends