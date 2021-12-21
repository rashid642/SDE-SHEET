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
