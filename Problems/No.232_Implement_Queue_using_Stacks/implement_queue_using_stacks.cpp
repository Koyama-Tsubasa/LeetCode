class MyQueue {

private:
    std::stack<int> Input;
    std::stack<int> Output;

public:
    
    void push(int x) { Input.push(x); }
    
    int pop() {
        
        peek();
        int num = Output.top();
        Output.pop();
        return num;

    }
    
    int peek() {
        
        if (Output.empty()) {
            while (!Input.empty()) {

                Output.push(Input.top());
                Input.pop();

            }
        }

        return Output.top();

    }
    
    bool empty() { return (Input.empty() && Output.empty()); }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
