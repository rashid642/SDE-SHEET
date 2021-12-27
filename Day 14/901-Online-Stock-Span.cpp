class StockSpanner {
public:
    vector<int> v;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && v[st.top()] <= price){
            st.pop();
        }
        int ind = v.size();
        v.push_back(price);
        if(st.empty()){
            st.push(ind);
            return ind+1;
        }
        int res = ind - st.top();
        st.push(ind);
        return res;
    }
};
