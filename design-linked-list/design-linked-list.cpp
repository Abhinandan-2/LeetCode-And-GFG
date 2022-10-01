class node {
public : 
    int val;
    node *next;
    node(int v){
        val = v;
        next= NULL;
    }
};

class MyLinkedList {
    node *front, *rear;
public:
    MyLinkedList() {
        front = NULL;
        rear = NULL;
    }
    
    int get(int index) {
        node *q = front;
        // while(q)
        // {
        //     cout<<q->val<<" ";
        //     q=q->next;
        // }
        // cout<<endl;
        if(front==NULL) return -1;
        node *p = front;
        while(p&&index--) p=p->next;
        if(p==NULL) return -1;
        return p->val;
    }
    
    void addAtHead(int val) {
        node *t = new node(val);
        t->next = front;
        front = t;
        if(rear==NULL) rear = t;
        return ;
    }
    
    void addAtTail(int val) {
        node *t = new node(val);
        if(rear!=NULL) rear->next = t;
        rear = t;
        if(front==NULL) front = t;
        return ;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        index--;
        node *p = front;
        while(p&&index--) p=p->next;
        if(p==NULL) return;
        if(p->next==NULL) addAtTail(val);
        else{
            node *t = new node(val);
            t->next = p->next;
            p->next = t;
        }
        return ;
    }
    
    void deleteAtIndex(int index) {
        node *p= front,*q;
        if(index==0){
            front = front->next;
            p->next = NULL;
            delete(p);
            if(front==NULL) rear = NULL;
            return;
        }
        index--;
        while(p&&index--) p=p->next;
        if(p==rear||p==NULL) return ;
        if(p->next==rear){
            rear = p;
            p= p->next;
            rear->next = NULL;
            delete(p);
            return;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        delete(q);
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */