//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> giveVector(Node *a){
        // cout<<a->data;
        vector<vector<int>> first;
        vector<int > h;
        int i =1 ;
        queue<Node*> q;
        Node *p;
        q.push(a);
        while(!q.empty()){
            p = q.front();
            q.pop();
            // cout<<p->data;
            h.push_back(p->data);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            i--;
            if(i==0){
                // for(auto j:h) cout<<j<<" ";
                first.push_back(h);
                i = q.size();
                h.clear();
            }
        }
        return first;
    }
    
    bool areAnagrams(Node *a, Node *b){
        
        vector<vector<int>> first, second;
        unordered_map<int,int> m,v;
        first = giveVector(a);
        second = giveVector(b);
        // for(auto i:first){ for(auto j:i) cout<<j<<" "; cout<<endl;}
        // cout<<endl;
        // for(auto i:second){ for(auto j:i) cout<<j<<" "; cout<<endl;}
        if(first.size()!=second.size()) return 0;
        int n = first.size();
        
        for(int i=0;i<n;i++){
            if(first[i].size()!=second[i].size()) return 0;
            for(auto j:first[i]) m[j]++;
            for(auto j:second[i]) v[j]++;
            if(m!=v) return 0;
            m.clear();
            v.clear();
        }
        
        return 1;
        
        
    }
};


// 1 2 2
// 1 3 3


//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends