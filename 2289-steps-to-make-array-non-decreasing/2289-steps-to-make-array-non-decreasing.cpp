class Node{
    
    public :
    int val;
    Node* next;
    Node* pre;
    Node(int v)
    {
        val = v;
        next= NULL;
        pre = NULL;
    }
    
};

class Solution {
public:
    
    Node* createList(vector<int> &a)
    {
        Node *r = new Node(a[0]),*t,*p;
        p = r;
        for(int i=1;i<a.size();i++)
        {
            t = new Node(a[i]);
            p->next = t;
            t->pre = p;
            p=t;
        }
        return r;
    }
    
    int reducedList(Node* a)
    {
        int ans = 0,res=0;
        Node *p = a->next;
        while(p->next)
        {
            if(p->val<p->next->val)
            {
                p->next->pre = p->pre;
                p->pre->next = p->next;
                p = p->pre;
                ans++;
                res = max(res,ans);
            }
            else
            {
                p = p->next;
                if(ans!=0)
                    ans--;
                res = max(res,ans);
            }
        }
        
        return res;
        
    }
    
    int totalSteps(vector<int>& a) {
        
        reverse(a.begin(),a.end());
        Node *head = createList(a),*t = new Node(INT_MAX);
        
        t->next = head;
        head->pre = t;
        head= t;
        
        int ans = reducedList(head);
        
        return ans;
        
        
    }
};