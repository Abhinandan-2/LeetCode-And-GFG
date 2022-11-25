//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    
    Node* createTree(string &a,int &i){
        // cout<<i<<" ";
        Node *ans = NULL;
        int val =0, n = a.size() ;
        if(i>=n) return ans;
        while(i<n&&a[i]>=48&&a[i]<=57){
            
            val *= 10;
            val += a[i]-48;
            i++;
            
        }
        if(val!=0)
        ans = new Node(val);
        // ans->data = val;
        if(i>=n) return ans;
        if(a[i]==')'){
            i++;
            return ans;
        }
        if(a[i]=='('){
            i++;
            ans->left = createTree(a,i);
        }
        if(a[i]==')'){
            i++;
            return ans;
        }
        if(a[i]=='('){
            i++;
            ans->right = createTree(a,i);
        }
        if(i>=n) return ans;
        i++;
        return ans;
       
    }
    
    Node *treeFromString(string a){
        
        int n =a.size(), i= 0;
        
        
        return createTree(a,i);
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends