class MyCircularDeque {

private:
    std::vector<int> DQueue;
    int MAX_size, curr_size;
    int front, rear;

public:
    MyCircularDeque(int k) {
        
        MAX_size = k;
        curr_size = 0;
        DQueue.resize(MAX_size);
        front = 0;

    }
    
    bool insertFront(int value) {
        
        if (isFull()) return false;
        else {

            front = (front - 1 + MAX_size)%MAX_size;
            DQueue[front] = value;
            curr_size++;
            return true;

        }

    }
    
    bool insertLast(int value) {
        
        if (isFull()) return false;
        else {

            DQueue[(front + curr_size)%MAX_size] = value;
            curr_size++;
            return true;

        }

    }
    
    bool deleteFront() {
        
        if (isEmpty()) return false;
        else {

            front = (front + 1)%MAX_size;
            curr_size--;
            return true;

        }

    }
    
    bool deleteLast() {
        
        if (isEmpty()) return false;
        else {

            curr_size--;
            return true;

        }

    }
    
    int getFront() {return isEmpty() ? -1 : DQueue[front];}
    
    int getRear() {return isEmpty() ? -1 : DQueue[(front + curr_size - 1)%MAX_size];}
    
    bool isEmpty() {return (curr_size == 0);}
    
    bool isFull() {return (curr_size == MAX_size);}
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
