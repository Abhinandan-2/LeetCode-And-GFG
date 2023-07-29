//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


void findTotalNodes(Node *a,int &total){
    if(!a) return ;
    findTotalNodes(a->left,total);
    total++;
    findTotalNodes(a->right,total);
    return;
}

void findANS(Node *a,int &total,int &f,float &ans){
    if(!a) return ;
    findANS(a->left,total,f,ans);
    total--;
    if(f==1){
        if(total==0){
            ans += a->data;
            total++;
            f=0;
        }
    }
    if(f==0){
        if(total==0){
            ans+=a->data;
            return ;
        }
    }
    findANS(a->right,total,f,ans);
    return ;
}

float findMedian(struct Node *a){
    int total =0,f=0,g ;
    float  ans=0;
    findTotalNodes(a,total);
    if(total%2==0) f=1;
    total = (total+1)/2;
    g = f;
    findANS(a,total,f,ans);
    if(g==1) ans/=2;
    return ans;
}

