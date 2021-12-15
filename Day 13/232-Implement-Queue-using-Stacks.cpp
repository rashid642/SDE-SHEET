class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st1.empty()){
            return -1;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int a=st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int a=st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


//optimized

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int a = output.top();
            output.pop();
            return a;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int a = output.top();
        output.pop();
        return a;
    }
    
    int peek() {
        if(!output.empty()){
            int a = output.top();
            return a;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int a = output.top();
        return a;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */