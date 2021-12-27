//brute force

class MinStack {
public:
    stack <long long> st;
    vector<long long> v;
    long long min;
    MinStack() {
        min=LLONG_MAX;
    }
    
    void push(long long val) {
        st.push(val); 
        v.push_back(val);
    }
    
    void pop() {
        long long a = st.top();
        st.pop();
        vector<long long>::iterator it = find(v.begin(), v.end(), a);
        v.erase(it);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        sort(v.begin(), v.end());
        return v.front();
    }
};

//optimzied

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || s2.top()>=val)s2.push(val);
    }
    
    void pop() {
        if(s1.top()==s2.top())s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();        
    }
    
    int getMin() {
        return s2.top();
    }
};

