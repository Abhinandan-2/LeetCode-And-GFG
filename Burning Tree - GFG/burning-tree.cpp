// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
  void makeGraph(Node *r,unordered_map<int,vector<int>> &a,int p)
  {
      if(r)
      {
          if(r->left)
              a[r->data].push_back(r->left->data);
          if(r->right)
              a[r->data].push_back(r->right->data);   
          if(p!=-1)
              a[r->data].push_back(p);
          makeGraph(r->left,a,r->data);
          makeGraph(r->right,a,r->data);
      }
      return ;
  }
  
    int minTime(Node* r, int t) 
    {
        unordered_map<int,vector<int>> a;
        unordered_map<int,int> v;
        makeGraph(r,a,-1);
        int p,h;
        queue<int> q;
        q.push(t);
        v[t]=1;
        int ans=-1;
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                
                for(int i=0;i<a[p].size();i++)
                {
                    if(!v.count(a[p][i]))
                    {
                        q.push(a[p][i]);
                        v[a[p][i]]=1;
                    }
                }
                
            }
        }
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends