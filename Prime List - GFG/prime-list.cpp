//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *a){
        
        vector<int> num(10008,0),prime;
        for(int i=2;i<10008;i++) if(num[i]==0){
            prime.push_back(i);
            for(int j=i*i;j<10008;j+=i) num[j] = 1; 
        }
        
        Node *p = a;
        int diff1 , diff2,in;
        while(p){
            in  = upper_bound(prime.begin(),prime.end(),p->val)-prime.begin();
            if(in==0) p->val = prime[in];
            else{
                diff1 = p->val-prime[in-1];
                diff2 = prime[in]-p->val;
                if(diff1<=diff2) p->val = prime[in-1];
                else p->val = prime[in];
            }
            p=p->next;
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends