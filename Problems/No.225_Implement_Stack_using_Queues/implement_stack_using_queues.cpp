class MyStack {

private:
    std::queue<int> Queue;

public:
    
    void push(int x) { Queue.push(x); }
    
    int pop() {

        int item;

        for (int i=0; i<Queue.size()-1; i++) {

            Queue.push(Queue.front());
            Queue.pop();

        }

        item = Queue.front();
        Queue.pop();

        return item;
        
    }
    
    int top() { return Queue.back(); }
    
    bool empty() { return Queue.empty(); }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
