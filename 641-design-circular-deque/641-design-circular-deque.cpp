class node{
  public : 
    int val;
    node *next,*pre;
    node(int v)
    {
        val = v;
        next = NULL;
        pre = NULL;
    }
    
};

class MyCircularDeque {
    
    node *front , *rear;
    int n , size ;
    
public:
    MyCircularDeque(int k) {
        front = NULL;
        rear = NULL;
        n = k;
        size =0 ;
    }
    
    bool insertFront(int value) {
        
        if(size==n)
            return false;
        
        node *t = new node(value);
        if(front==NULL)
        {
            front = t;
            rear = t;
        }
        else
        {
            front->next = t;
            t->pre = front;
            front = front->next;
        }
        size++;
        return true;
        
        
    }
    
    bool insertLast(int value) {
        
        
        if(size==n)
            return false;
        
        node *t = new node(value);
        if(rear==NULL)
        {
            front = t;
            rear = t;
        }
        else
        {
            t->next = rear;
            rear->pre = t;
            rear = t;
        }
        size++;
        return true;
        
    }
    
    bool deleteFront() {
        
        if(isEmpty())
            return false;
        node *t;
        if(front==rear)
        {
            t = front;
            front = NULL;
            rear = NULL;
            delete(t);
            size--;
            return true;
        }
        front=front->pre;
        front->next->pre = NULL;
        t = front->next;
        front->next = NULL;
        delete(t);
        size--;
        return true;
        
    }
    
    bool deleteLast() {
        
        if(isEmpty())
            return false;
        node *t ;
        if(front==rear)
        {
            t = front;
            front = NULL;
            rear = NULL;
            delete(t);
            size--;
            return true;
        }
        rear=rear->next;
        rear->pre->next = NULL;
        t = rear->pre;
        rear->pre = NULL;
        delete(t);
        size--;
        return true;
    }
    
    int getFront() {
        
        if(front==NULL)
            return -1;
        return front->val;
        
    }
    
    int getRear() {
        
        if(rear==NULL)
            return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        
        if(front==NULL)
            return true;
        return false;
        
    }
    
    bool isFull() {
        
        if(size==n)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */