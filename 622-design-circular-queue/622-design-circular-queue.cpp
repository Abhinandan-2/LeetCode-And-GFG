class MyCircularQueue {
    vector<int> q;
    int front,rear,cap;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        front = -1;
        rear = -1;
        cap = k; 
    }
    bool enQueue(int value) {
        if(isFull()) return 0;
        if(rear==-1){
            front =0 ;
            rear = 0;
        }
        else{
            rear++;
            rear %= cap;
        }
        q[rear] = value;
        return 1;
    }
    bool deQueue() {
        if(isEmpty()) return 0;
        if(rear==front){
            rear = -1;
            front = -1;
            return 1;
        }
        front++;
        front %= cap;
        return 1;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if(front==-1) return 1;
        return 0;
    }
    
    bool isFull() {
        if((rear+1)%cap==front) return 1;
        return 0;
    }
};