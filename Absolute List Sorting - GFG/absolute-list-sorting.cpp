//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* reverse(Node *a){
        if(!a||!a->next) return a;
        Node *p = a, *q = a->next, *r = NULL;
        while(p){
            p->next = r;
            r = p;
            p = q;
            if(q) q=q->next;
        }
        return r;
    }

    Node* sortList(Node* a){
        
        Node *p =NULL, *q = NULL, *b =NULL,*t = a ;
        a = NULL;
        while(t){
            if(t->data>=0){
                if(p==NULL){
                    a = t;
                    p = t;
                }
                else{
                    p->next = t;
                    p=p->next;
                }
            }
            else{
                if(q==NULL){
                    b = t;
                    q = t;
                }
                else{
                    q->next = t;
                    q=q->next;
                }
            }
            t=t->next;
        }
        if(b==NULL) return a;
        q->next = NULL;
        b = reverse(b);
        if(a==NULL) return b;
        p->next = NULL;
        q = b;
        while(q->next) q=q->next;
        q->next = a;
        return b;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends